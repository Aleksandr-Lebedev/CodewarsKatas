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

} 
namespace athl_assoc
{
	TimeResult TimeResult::from_str(std::string_view tm_result_strv)
	{
		TimeResult tm_result;
		std::string tm_result_str(tm_result_strv);

		const char* delim = "|";
		char* next_token  = nullptr;

		auto token       = strtok_s(tm_result_str.data(), delim, &next_token);
		auto token_end   = strchr(token, '\0');
		tm_result._hours = TRY_CONVERT_ANY(token, &token_end);

		token              = strtok_s(nullptr, delim, &next_token);
		token_end          = strchr(token, '\0');
		tm_result._minutes = TRY_CONVERT_60(token, &token_end);

		token              = strtok_s(nullptr, delim, &next_token);
		token_end          = strchr(token, '\0');
		tm_result._seconds = TRY_CONVERT_60(token, &token_end);

		return tm_result;
	}
}

