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
		// Copy of elements into dynamic memory. This was done here only because the original task required
		// us to pass the first argument as a c-ref to the std::string.
		std::string race_results(race_results_cstr);
		auto stats = calculate_statistics(race_results);
		const auto stats_length = static_cast<int>(stats.length());
		if (race_stats_out_buf != nullptr)
		{
			const auto error = strncpy_s(race_stats_out_buf, sizeof(char) * race_stats_out_buf_length, stats.c_str(), stats_length);
			if (error)
			{
				throw make_return_value_exception("Copy to 'race_stats_out_buf' failed. An error occurred: %d", error);
			}
		}

		return stats_length;
	}

	int race_results_str_max_length() noexcept
	{
		return MAX_RACE_RESULT_STRING_CHARACTERS;
	}
}
