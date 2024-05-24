#include "pch.h"
#include "athl_assoc_stat_api.h"
#include "return_codes.h"

namespace codewars
{
class CodewarsTests : public testing::Test
{
protected:
	void do_test(const char* race_results, const char* expected)
	{
		auto expected_length = static_cast<int>(strlen(expected));
		auto actual_length = expected_length + 1;

		std::string statistics(actual_length, '\0');

		auto ret_code = calculate_race_statistics(race_results, statistics.data(), &actual_length);

		ASSERT_EQ(ret_code, COMMON_NO_ERROR);
		statistics.resize(actual_length);

		EXPECT_EQ(expected_length, actual_length);
		ASSERT_STREQ(expected, statistics.c_str());
	}
};

TEST_F(CodewarsTests, TestFixed_1)
{
	const char* race_results = "01|15|59, 1|47|16, 01|17|20, 1|32|34, 2|17|17";
	const char* expected = "Range: 01|01|18 Average: 01|38|05 Median: 01|32|34";

	do_test(race_results, expected);
}

TEST_F(CodewarsTests, TestFixed_2)
{
	const char* race_results = "02|15|59, 2|47|16, 02|17|20, 2|32|34, 2|17|17, 2|22|00, 2|31|41";
	const char* expected = "Range: 00|31|17 Average: 02|26|18 Median: 02|22|00";

	do_test(race_results, expected);
}
}

