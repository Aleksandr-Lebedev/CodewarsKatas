#include "pch.h"
#include "athl_assoc_stat_api.h"
#include "parse_error.h"

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
