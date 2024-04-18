#include "pch.h"
#include "run_time_result.h"
namespace athl_assoc
{
	TimeResult TimeResult::from_str(const char* tm_result_cstr)
	{
		TimeResult tm_result;
		std::string tm_result_str(tm_result_cstr);

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
}

