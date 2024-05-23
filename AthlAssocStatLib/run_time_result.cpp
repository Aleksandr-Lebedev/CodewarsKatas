#include "pch.h"
#include "run_time_result.h"

namespace
{
	template<typename T, unsigned MAX>
	T try_convert_to_number(const char* cstr, char** cstr_end)
	{
		const auto number = static_cast<T>(strtoul(cstr, cstr_end, 10));
		// check if number is out of range
		if constexpr (MAX > 0)
		{
			if (number > MAX)
			{
				constexpr unsigned BUFF_SIZE = 64;
				const char* hint = "Value %u is out of range [0;%u)";
				char error_description_buffer[BUFF_SIZE];
				const auto chars_written =
					sprintf_s(error_description_buffer, BUFF_SIZE, hint, number, MAX);
				assert(chars_written > 0);
				throw std::out_of_range(error_description_buffer);
			}
		}
		return number;
	}

#define TRY_CONVERT_ANY try_convert_to_number<unsigned, 0>
#define TRY_CONVERT_60 try_convert_to_number<unsigned, 60>

	constexpr unsigned substract_values(unsigned left, unsigned right)
	{
		return left > right ? left - right : right - left;
	}
} 
namespace athl_assoc
{
	TimeResult TimeResult::from_str(std::string_view tm_result_strv)
	{
		TimeResult tm_result;
		std::string tm_result_str(tm_result_strv);

		const char* delim = "|";
		char* next_token = nullptr;

		auto token = strtok_s(tm_result_str.data(), delim, &next_token);
		auto token_end = strchr(token, '\0');
		tm_result._hours = TRY_CONVERT_ANY(token, &token_end);

		token = strtok_s(nullptr, delim, &next_token);
		token_end = strchr(token, '\0');
		tm_result._minutes = TRY_CONVERT_60(token, &token_end);

		token = strtok_s(nullptr, delim, &next_token);
		token_end = strchr(token, '\0');
		tm_result._seconds = TRY_CONVERT_60(token, &token_end);

		tm_result.reset_total_seconds();

		return tm_result;
	}

	std::string TimeResult::to_str() const noexcept
	{
		constexpr unsigned BUFF_SIZE = 15;

		const char* format = "%2u|%2u|%2u";
		std::string str_result(BUFF_SIZE, '\0');
		auto chars_written = sprintf_s(str_result.data(), BUFF_SIZE, format, _hours, _minutes, _seconds);
		assert(chars_written > 0);
		str_result.resize(chars_written);

		return str_result;
	}

	std::string TimeResult::to_str(std::string_view prefix) const noexcept
	{
		std::string str_result(prefix);
		str_result.append(": ").append(to_str());

		return str_result;

		// constexpr unsigned BUFF_SIZE         = 21;
		// constexpr unsigned MAX_PREFIX_LENGTH = 10;

		// if (prefix.size() > MAX_PREFIX_LENGTH)
		// {
		// 	prefix.remove_prefix(prefix.size() - MAX_PREFIX_LENGTH);
		// }
		// std::string prefix_str(prefix);

		// const char* format = "%s: %2u|%2u|%2u";
		// std::string str_result(BUFF_SIZE, '\0');
		// auto chars_written = sprintf_s(str_result.data(), BUFF_SIZE, format, prefix_str.c_str(), _hours, _minutes, _seconds);
		// assert(chars_written > 0);
		// str_result.resize(chars_written);

		// return str_result;
	}

	bool TimeResult::operator<(const TimeResult& rhs) const noexcept
	{
		return _total_seconds < rhs._total_seconds;
	}

	TimeResult TimeResult::operator-(const TimeResult& rhs) const noexcept
	{
		unsigned total_seconds = substract_values(_total_seconds, rhs._total_seconds);
		return TimeResult{ total_seconds };
	}

	TimeResult TimeResult::operator+(const TimeResult& rhs) const noexcept
	{
		return TimeResult{ _total_seconds + rhs._total_seconds };
	}

	void TimeResult::divide(unsigned denominator)
	{
		if (denominator == 0)
		{
			throw std::invalid_argument("The denominator cannot be equal to zero.");
		}

		_total_seconds /= denominator;
		reset_hms();
	}

	void TimeResult::reset_hms() noexcept
	{
		auto div = std::ldiv(_total_seconds, SECONDS_IN_HOURS);
		_hours = div.quot;

		div = std::ldiv(div.rem, SECONDS_IN_MINUTE);
		_minutes = div.quot;

		_seconds = div.rem;
	}
}

