#include "pch.h"

#include "athl_assoc_stat_api.h"
#include "calculate_stats.h"
#include "parse_error.h"

namespace
{
	inline int search_null_term(const char* const cstr, int max_offset)
	{
		int offset = 0;
		for (; offset < max_offset; ++offset)
		{
			if (cstr[offset] == '\0')
			{
				break;
			}
		}
		return offset;
	}
}

namespace athl_assoc::api
{
	int calculate_race_statistics(const char* const race_results_cstr, char* race_stats_out_buf, int race_stats_out_buf_length)
	{
		const auto max_results_cstr_length = MAX_RACE_RESULT_STRING_CHARACTERS + 1;

		if (race_results_cstr == nullptr)
		{
			throw std::invalid_argument{"Argument 'race_results_cstr' is a null pointer"};
		}

		if (search_null_term(race_results_cstr, max_results_cstr_length + 1) > max_results_cstr_length)
		{
			throw std::invalid_argument{"Argument 'race_results_cstr' is too long or invalid"};
		}

		return 0;
	}

	int race_results_str_max_length() noexcept
	{
		return MAX_RACE_RESULT_STRING_CHARACTERS;
	}
}
