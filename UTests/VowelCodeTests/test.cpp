#include "pch.h"
#include "vowel_code_api.h"

TEST(TestCodewarsCases, TestEncode_1) {
	const std::string origin{ "hello" };
	const std::string expected{ "h2ll4" };

	std::string actual(origin.size() + 1, '\0');
	const auto ret = encode_vwc(origin.c_str(), static_cast<int>(origin.size()),
		const_cast<char*>(actual.data()), static_cast<int>(actual.size()));

	EXPECT_EQ(ret, NO_ERROR_VWC);
	EXPECT_EQ(actual, expected);
}

TEST(TestCodewarsCases, TestEncode_2) {
	const std::string origin{ "How are you today?" };
	const std::string expected{ "H4w 1r2 y45 t4d1y?" };

	std::string actual(origin.size() + 1, '\0');
	const auto ret = encode_vwc(origin.c_str(), static_cast<int>(origin.size()),
		const_cast<char*>(actual.data()), static_cast<int>(actual.size()));

	EXPECT_EQ(ret, NO_ERROR_VWC);
	EXPECT_EQ(actual, expected);
}

TEST(TestCodewarsCases, TestEncode_3) {
	const std::string origin{ "This is an encoding test." };
	const std::string expected{ "Th3s 3s 1n 2nc4d3ng t2st." };

	std::string actual(origin.size() + 1, '\0');
	const auto ret = encode_vwc(origin.c_str(), static_cast<int>(origin.size()),
		const_cast<char*>(actual.data()), static_cast<int>(actual.size()));

	EXPECT_EQ(ret, NO_ERROR_VWC);
	EXPECT_EQ(actual, expected);
}
