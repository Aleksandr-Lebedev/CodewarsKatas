#include "pch.h"

#include "calculate_stats.h"
#include "run_time_result.h"

namespace
{
	std::vector<athl_assoc::TimeResult> generate_time_results(const std::string& race_results)
	{
		using athl_assoc::TimeResult;
		constexpr int MATCH_GROUP = 1;

		static const auto re = std::regex("(?:,\\w?)?(\\d+\\|[0-5]\\d\\|[0-5]\\d)");

		auto iter = std::sregex_token_iterator(race_results.cbegin(), race_results.cend(), re, MATCH_GROUP);

		std::vector<TimeResult> run_results;
		std::for_each(iter, std::sregex_token_iterator{}, [&run_results](auto& match) {
			run_results.push_back(TimeResult::from_str(match.str()));
			});
		return run_results;
	}
}

namespace athl_assoc
{
	std::string calculate_statistics(const std::string& race_results)
	{
		const auto run_results = generate_time_results(race_results);



		return std::string("abc");
	}
}

