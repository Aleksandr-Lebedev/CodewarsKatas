#include "pch.h"
#include "athl_assoc_stat_api.h"
#include "parse_error.h"

using namespace athl_assoc::api;

TEST(TestErrorHandling, TestRaceResultIsNullptr) {
	ASSERT_THROW(calculate_race_statistics(nullptr, nullptr, 0), std::invalid_argument);
}

/*
TEST(TestErrorHandling, TestParseError) {
	std::string dummy{ 10, 'a' };
	ASSERT_THROW(calculate_race_statistics(dummy.data(), nullptr, 0), ParseError);
}
*/
