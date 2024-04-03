#include "pch.h"
#include "athl_assoc_stat_api.h"
#include "parse_error.h"

using namespace athl_assoc;

TEST(TestErrorHandling, TestRaceResultIsNullptr) {
	ASSERT_THROW(calculate_race_statistics(nullptr, 10, nullptr, 0), std::invalid_argument);
}

TEST(TestErrorHandling, TestRaceResultStringLengthIsZero) {
	std::string dummy{ 10, 'a' };
	ASSERT_THROW(calculate_race_statistics(dummy.data(), 0, nullptr, 0), std::length_error);
}

TEST(TestErrorHandling, TestParseError) {
	std::string dummy{ 10, 'a' };
	ASSERT_THROW(calculate_race_statistics(dummy.data(), dummy.length(), nullptr, 0), ParseError);
}