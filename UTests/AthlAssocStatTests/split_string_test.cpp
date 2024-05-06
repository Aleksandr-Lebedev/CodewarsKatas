#include "pch.h"
#include "athl_assoc_stat_api.h"

using SplitResultSmartPtr = std::unique_ptr<IStringSplitResult, StringSplitResultDeleter>;

namespace split_string_tests
{
	class StringSplitTests : public testing::Test
	{
	protected:
		void do_string_test(const char* cstr, char delimiter, const std::vector<std::string>& expected)
		{
			auto split_result = call_split_string(cstr, delimiter);
			ASSERT_EQ(split_result->count(), expected.size());
			for (const auto& str : expected)
			{
				EXPECT_STREQ(split_result->next(), str.c_str());
			}
		}

		SplitResultSmartPtr call_split_string(const char* cstr, char delimiter)
		{
			IStringSplitResult* split_result_ptr = nullptr;
			const auto error = split_string(&split_result_ptr, cstr, delimiter);
			EXPECT_EQ(error, COMMON_NO_ERROR);
			EXPECT_NE(split_result_ptr, nullptr);
			return SplitResultSmartPtr(split_result_ptr, unbind_string_split_result);
		}
	};

	TEST_F(StringSplitTests, Whitespaces)
	{
		do_string_test("abc def fgh ijk", ' ', { "abc", "def", "fgh", "ijk" });
	}

	TEST_F(StringSplitTests, CommaWithTrailing)
	{
		do_string_test("abc,def,fgh,ijk,", ',', { "abc", "def", "fgh", "ijk" });
	}

	TEST_F(StringSplitTests, CommaAndWhitespace)
	{
		do_string_test("abc, def, fgh, ijk", ',', { "abc", "def", "fgh", "ijk" });
	}

	TEST_F(StringSplitTests, SingleString)
	{
		do_string_test("abc", ',', { "abc" });
	}

	TEST_F(StringSplitTests, EmptyString)
	{
		auto split_result = call_split_string("", ',');
		ASSERT_EQ(split_result->count(), 0);
	}
}
