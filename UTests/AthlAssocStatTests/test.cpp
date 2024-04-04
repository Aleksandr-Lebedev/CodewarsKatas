#include "pch.h"
#include "athl_assoc_stat_api.h"
#include "custom_exceptions.h"

using namespace athl_assoc::api;

TEST(TestErrorHandling, TestRaceResultIsNullptr) {
	ASSERT_THROW(calculate_race_statistics(nullptr, nullptr, 0), std::invalid_argument);
}

TEST(TestErrorHandling, TestTooLongRaceResultsString) {
	const auto dummy_str_length = static_cast<std::string::size_type>(race_results_str_max_length() * 2);
	std::string dummy(dummy_str_length, 'a');
	ASSERT_THROW(calculate_race_statistics(dummy.c_str(), nullptr, 0), std::invalid_argument);
}

/*
TEST(TestErrorHandling, TestParseError) {
	std::string dummy{ 10, 'a' };
	ASSERT_THROW(calculate_race_statistics(dummy.data(), nullptr, 0), ParseError);
}
*/

/*
TEST(Codewars, TestFixed_1) {
	const char* race_results = "01|15|59, 1|47|16, 01|17|20, 1|32|34, 2|17|17";
	const char* expected = "Range: 01|01|18 Average: 01|38|05 Median: 01|32|34";
	const auto expected_length = static_cast<int>(strlen(expected));
	std::string statistics(expected_length, 'a');

	const auto actual_length = calculate_race_statistics(race_results, statistics.data(), expected_length);
	statistics.resize(actual_length);

	EXPECT_EQ(expected_length, actual_length);
	ASSERT_STREQ(expected, statistics.c_str());
}
*/

/*
TEST(Codewars, TestFixed_2) {
	const char* race_results = "02|15|59, 2|47|16, 02|17|20, 2|32|34, 2|17|17, 2|22|00, 2|31|41";
	const char* expected = "Range: 00|31|17 Average: 02|26|18 Median: 02|22|00";
	const auto expected_length = static_cast<int>(strlen(expected));
	std::string statistics(expected_length, 'a');

	const auto actual_length = calculate_race_statistics(race_results, statistics.data(), expected_length);
	statistics.resize(actual_length);

	EXPECT_EQ(expected_length, actual_length);
	ASSERT_STREQ(expected, statistics.c_str());
}
*/

