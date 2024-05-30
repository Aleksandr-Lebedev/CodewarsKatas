#include "pch.h"
#include "athl_assoc_stat_api.h"
#include "return_codes.h"

namespace error_handling
{
TEST(TestErrorHandling, TestRaceResultIsNullptr)
{
    int length = 0;
    const auto ret_code = calculate_race_statistics(nullptr, nullptr, &length);
    ASSERT_NE(ret_code, COMMON_NO_ERROR);
    EXPECT_EQ(ret_code, INPUT_STRING_NULLPTR);
}

TEST(TestErrorHandling, TestTooLongRaceResultsString)
{
    const auto dummy_str_length = static_cast<std::string::size_type>(race_results_str_max_length() * 2);
    std::string dummy(dummy_str_length, 'a');
    int length = 0;
    const auto ret_code = calculate_race_statistics(dummy.c_str(), nullptr, &length);
    ASSERT_NE(ret_code, COMMON_NO_ERROR);
    EXPECT_EQ(ret_code, INPUT_STRING_INVALID);
}

TEST(TestErrorHandling, TestParseError)
{
    const char* race_results = "01|1...., l|47|16, o1|17;20";
    int dummy_str_length = 51;
    std::string dummy(dummy_str_length, '\0');
    auto ret_code = calculate_race_statistics(race_results, dummy.data(), &dummy_str_length);
    ASSERT_NE(ret_code, COMMON_NO_ERROR);
    EXPECT_EQ(ret_code, INPUT_STRING_INVALID);
}

TEST(TestErrorHandling, TestTooFewTimestamps)
{
    const char* race_results = "01|15|59";
    int dummy_str_length = 51;
    std::string dummy(dummy_str_length, '\0');
    auto ret_code = calculate_race_statistics(race_results, dummy.data(), &dummy_str_length);
    ASSERT_NE(ret_code, COMMON_NO_ERROR);
    EXPECT_EQ(ret_code, INPUT_STRING_INVALID);
}

TEST(TestErrorHandling, TestOutputBufferTooShort)
{
    const char* race_results = "01|15|59, 1|47|16, 01|17|20, 1|32|34, 2|17|17";
    int dummy_str_length = 50;
    std::string dummy(dummy_str_length, '\0');
    auto ret_code = calculate_race_statistics(race_results, dummy.data(), &dummy_str_length);
    ASSERT_NE(ret_code, COMMON_NO_ERROR);
    EXPECT_EQ(ret_code, STRING_SIZE_TOO_LOWER);
}
}

