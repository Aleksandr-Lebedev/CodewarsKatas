#include "pch.h"

#include "calculate_stats.h"

namespace
{
	
}

namespace athl_assoc
{
	class TimeResult
	{
		TimeResult(unsigned h, unsigned m, unsigned s) noexcept
			: _hours(h)
			, _minutes(m)
			, _seconds(s)
		{}

		static TimeResult from_str(std::string tm_result_str)
		{
			// constexpr char delim{ '|' };
			TimeResult tm_result;
			// std::string_view::size_type left = 0;
			// auto right = tm_result_str.find(delim, left);
			// if (right != std::string_view::npos)
			// {
			// 	tm_result._hours = static_cast<unsigned>(std::stoi(tm_result_str.substr(left, right)));
			// }
			// left = right + 1;
			// right = tm_result_str.find(delim, left);
			// if (right != std::string_view::npos)
			// {
			// 	tm_result._minutes = static_cast<unsigned>(std::stoi(tm_result_str.substr(left, right)));
			// }
			// tm_result._seconds = static_cast<unsigned>(std::stoi(tm_result_str.substr(right + 1)));

			const char* delim = "|";
			char* next_token = nullptr;

			auto token = strtok_s(tm_result_str.data(), delim, &next_token);
			auto token_end = strchr(token, '\0');
			tm_result._hours = static_cast<unsigned>(strtoul(token, &token_end, 10));

			token = strtok_s(nullptr, delim, &next_token);
			token_end = strchr(token, '\0');
			tm_result._minutes = static_cast<unsigned>(strtoul(token, &token_end, 10));

			token = strtok_s(nullptr, delim, &next_token);
			token_end = strchr(token, '\0');
			tm_result._seconds = static_cast<unsigned>(strtoul(token, &token_end, 10));

			return tm_result;
		}

		unsigned Hours() const noexcept
		{
			return _hours;
		}

		unsigned Minutes() const noexcept
		{
			return _minutes;
		}

		unsigned Seconds() const noexcept
		{
			return _seconds;
		}

	private:
		TimeResult() = default;

		unsigned _hours;
		unsigned _minutes;
		unsigned _seconds;
	};

	std::string calculate_statistics(const std::string& race_results)
	{
		return std::string("abc");
	}
}

