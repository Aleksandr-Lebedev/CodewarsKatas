#include "pch.h"

#include "run_time_result.h"

namespace time_result_tests
{
	TEST(TimeResultTests, RegularString)
	{
		const auto time_result = athl_assoc::TimeResult::from_str("10|32|12");

		ASSERT_EQ(time_result.Hours(), 10);
		ASSERT_EQ(time_result.Minutes(), 32);
		ASSERT_EQ(time_result.Seconds(), 12);
	}

	TEST(TimeResultTests, HourIsOneDigitOnly)
	{
		const auto time_result = athl_assoc::TimeResult::from_str("3|02|00");

		ASSERT_EQ(time_result.Hours(), 3);
		ASSERT_EQ(time_result.Minutes(), 2);
		ASSERT_EQ(time_result.Seconds(), 0);
	}

	TEST(TimeResultTests, ValuesOutOfRange)
	{
		EXPECT_THROW(athl_assoc::TimeResult::from_str("3|02|90"), std::out_of_range);
		EXPECT_THROW(athl_assoc::TimeResult::from_str("3|72|00"), std::out_of_range);
	}
}

