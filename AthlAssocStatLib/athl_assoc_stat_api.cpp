#include "pch.h"
#include "athl_assoc_stat_api.h"
#include "parse_error.h"

namespace athl_assoc
{
	int calculate_race_statistics(const char* const race_results_cstr, int race_results_cstr_length, char* race_stats_cstr, int race_stats_cstr_length)
	{
		if (race_results_cstr == nullptr)
		{
			throw std::invalid_argument{"Argument 'race_results_cstr' is a null pointer"};
		}

		if (race_results_cstr_length <= 0)
		{
			throw std::length_error{ "Argument 'race_results_cstr_length' is less or equal to zero" };
		}
		return 0;
	}
}
