#include "pch.h"

#include "calculate_stats.h"
#include "run_time_result.h"

namespace
{
	
}

namespace athl_assoc
{
	std::string calculate_statistics(const std::string& race_results)
	{
		constexpr int MATCH_GROUP = 1;

		static const auto re = std::regex("(?:,\\w?)?(\\d+\\|[0-5]\\d\\|[0-5]\\d)");

		std::vector<TimeResult> run_results;
		for (auto iter = std::sregex_token_iterator(race_results.cbegin(),
			race_results.cend(), re, MATCH_GROUP); iter != std::sregex_token_iterator{}; ++iter)
		{
			run_results.push_back(TimeResult::from_str(iter->str()));
		}
		return std::string("abc");
	}
}

