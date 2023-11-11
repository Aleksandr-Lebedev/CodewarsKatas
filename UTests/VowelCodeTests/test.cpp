#include "pch.h"
#include "vowel_code_api.h"

TEST(TestCodewarsCases, TestEncode_1) {
	const char* origin      = "hello";
	const auto  origin_size = static_cast<int>(strlen(origin));
	const char* expected    = "h2ll4";

	constexpr int encoded_buf_size{ 10 };
	char          encoded[encoded_buf_size];

	const auto ret = encode_vwc(origin, origin_size, encoded, encoded_buf_size);

	EXPECT_EQ(ret, NO_ERROR_VWC);
	EXPECT_STREQ(encoded, expected);
}

TEST(TestCodewarsCases, TestEncode_2) {
	const char* origin      = "How are you today?";
	const auto  origin_size = static_cast<int>(strlen(origin));
	const char* expected    = "H4w 1r2 y45 t4d1y?";

	constexpr int encoded_buf_size{ 20 };
	char          encoded[encoded_buf_size];

	const auto ret = encode_vwc(origin, origin_size, encoded, encoded_buf_size);

	EXPECT_EQ(ret, NO_ERROR_VWC);
	EXPECT_STREQ(encoded, expected);
}

TEST(TestCodewarsCases, TestEncode_3) {
	const char* origin      = "This is an encoding test.";
	const auto  origin_size = static_cast<int>(strlen(origin));
	const char* expected    = "Th3s 3s 1n 2nc4d3ng t2st.";

	constexpr int encoded_buf_size{ 30 };
	char          encoded[encoded_buf_size];

	const auto ret = encode_vwc(origin, origin_size, encoded, encoded_buf_size);

	EXPECT_EQ(ret, NO_ERROR_VWC);
	EXPECT_STREQ(encoded, expected);
}
