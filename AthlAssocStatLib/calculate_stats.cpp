#include "pch.h"

#include "calculate_stats.h"
#include "run_time_result.h"

using athl_assoc::TimeResult;
using TimeResultsVector = std::vector<TimeResult>;

using namespace std::string_view_literals;

constexpr auto     EMPTY_RESULTS_STR{ "Range: 00|00|00 Average: 00|00|00 Median: 00|00|00"sv };
constexpr unsigned MINIMUM_RUN_RESULTS_NUM{ 2 };

namespace
{
	TimeResultsVector generate_time_results(const std::string& race_results)
	{
		constexpr int MATCH_GROUP = 1;

		static const auto re = std::regex("(?:,\\w?)?(\\d+\\|[0-5]\\d\\|[0-5]\\d)");

		auto iter = std::sregex_token_iterator(race_results.cbegin(), race_results.cend(), re, MATCH_GROUP);

		TimeResultsVector run_results;
		std::for_each(iter, std::sregex_token_iterator{}, [&run_results](auto& match) {
			run_results.push_back(TimeResult::from_str(match.str()));
			});
		return run_results;
	}

	std::string convert_calculation_results_to_string(const TimeResult& range, const TimeResult& average, const TimeResult& median)
	{
		std::string results_string(EMPTY_RESULTS_STR.size(), '\0');

		results_string.assign("Range: ").append(range.to_str())
			          .append(" Average: ").append(average.to_str())
			          .append(" Median: ").append(median.to_str());

		results_string.shrink_to_fit();
		return results_string;
	}

	std::string convert_calculation_results_to_string(const TimeResult& single)
	{
		std::string results_string(EMPTY_RESULTS_STR.size(), '\0');
		
		const auto time_result_str = single.to_str();
		results_string.assign("Range: ").append(time_result_str)
			          .append(" Average: ").append(time_result_str)
			          .append(" Median: ").append(time_result_str);

		results_string.shrink_to_fit();
		return results_string;
	}

	inline TimeResult calculate_range(const TimeResultsVector& run_results)
	{
		return run_results.back() - run_results.front();
	}

	TimeResult calculate_average(const TimeResultsVector& run_results)
	{
		auto average = std::accumulate(run_results.cbegin(), run_results.cend(), TimeResult{});

		return average / static_cast<unsigned>(run_results.size());
	}

	TimeResult calculate_average(const TimeResult& first, const TimeResult& second)
	{
		auto median = first + second;

		return median / MINIMUM_RUN_RESULTS_NUM;
	}

	TimeResult calculate_median(const TimeResultsVector& run_results)
	{
		auto results_count = run_results.size();

		if (results_count == MINIMUM_RUN_RESULTS_NUM)
		{
			return calculate_average(run_results[0], run_results[1]);
		}
		else
		{
			auto median_idx = results_count / 2;
			if (results_count % 2 == 0)
			{
				return calculate_average(run_results[median_idx], run_results[median_idx + 1]);
			}
			else
			{
				return run_results[median_idx];
			}
		}
	}
}

namespace athl_assoc
{
	std::string calculate_statistics(const std::string& race_results)
	{
		auto run_results = generate_time_results(race_results);
		if (run_results.empty())
		{
			return std::string(EMPTY_RESULTS_STR);
		}
		else if (run_results.size() < MINIMUM_RUN_RESULTS_NUM)
		{
			return convert_calculation_results_to_string(run_results[0]);
		}

		std::sort(run_results.begin(), run_results.end());

		const auto range   = calculate_range(run_results);
		const auto average = calculate_average(run_results);
		const auto median  = calculate_median(run_results);

		return convert_calculation_results_to_string(range, average, median);
	}
}

