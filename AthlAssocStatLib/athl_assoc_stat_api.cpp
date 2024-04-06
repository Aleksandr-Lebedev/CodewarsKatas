#include "pch.h"

#include "athl_assoc_stat_api.h"
#include "auxiliary.h"
#include "calculate_stats.h"
#include "custom_exceptions.h"

namespace
{
	inline int search_null_term(const char* const cstr, int max_offset)
	{
		for (int offset = 0; offset < max_offset; ++offset)
		{
			if (cstr[offset] == '\0')
			{
				return offset;
			}
		}
		return max_offset;
	}
}

int calculate_race_statistics(const char* const race_results_cstr, char* race_stats_out_buf, int* race_stats_out_buf_length)
{
	const auto max_results_cstr_length = athl_assoc::MAX_RACE_RESULT_STRING_CHARACTERS + 1;

	if (race_results_cstr == nullptr)
	{
		return INPUT_STRING_PTR_NULL;
	}

	if (search_null_term(race_results_cstr, max_results_cstr_length + 1) > max_results_cstr_length)
	{
		return INPUT_STRING_INVALID;
	}

	if (race_stats_out_buf_length == nullptr)
	{
		return ARGUMENT_NULLPTR;
	}

	// Copy of elements into dynamic memory. This was done here only because the original task required
	// us to pass the first argument as a c-ref to the std::string.
	std::string race_results(race_results_cstr);
	auto stats = athl_assoc::calculate_statistics(race_results);
	const auto stats_length = static_cast<int>(stats.length());
	if (race_stats_out_buf != nullptr && *race_stats_out_buf_length > 0)
	{
		if (strncpy_s(race_stats_out_buf, sizeof(char) * *race_stats_out_buf_length, stats.c_str(), stats_length))
		{
			return OTHER_ERROR;
		}
	}

	*race_stats_out_buf_length = stats_length;
	return COMMON_NO_ERROR;
}

int race_results_str_max_length()
{
	return athl_assoc::MAX_RACE_RESULT_STRING_CHARACTERS;
}
