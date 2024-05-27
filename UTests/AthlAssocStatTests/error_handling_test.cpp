#include "pch.h"
#include "athl_assoc_stat_api.h"
#include "return_codes.h"

namespace error_handling
{
TEST(TestErrorHandling, TestRaceResultIsNullptr) {
	int length = 0;
	const auto ret_code = calculate_race_statistics(nullptr, nullptr, &length);
	ASSERT_EQ(ret_code, INPUT_STRING_NULLPTR);
}

TEST(TestErrorHandling, TestTooLongRaceResultsString) {
	const auto dummy_str_length = static_cast<std::string::size_type>(race_results_str_max_length() * 2);
	std::string dummy(dummy_str_length, 'a');
	int length = 0;
	const auto ret_code = calculate_race_statistics(dummy.c_str(), nullptr, &length);
	ASSERT_EQ(ret_code, INPUT_STRING_INVALID);
}

/*
TEST(TestErrorHandling, TestParseError) {
	std::string dummy{ 10, 'a' };
	ASSERT_THROW(calculate_race_statistics(dummy.data(), nullptr, 0), ParseError);
}
*/
}

