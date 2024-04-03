#include "pch.h"

#include "athl_assoc_stat_api.h"
#include "calculate_stats.h"
#include "parse_error.h"

namespace athl_assoc
{
	int calculate_race_statistics(const char* const race_results_cstr, char* race_stats_out_buf, int race_stats_out_buf_length)
	{
		if (race_results_cstr == nullptr)
		{
			throw std::invalid_argument{"Argument 'race_results_cstr' is a null pointer"};
		}

		return 0;
	}
}
