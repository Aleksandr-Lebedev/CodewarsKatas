#include "pch.h"
#include "vowel_code_api.h"

namespace
{
template<typename F, int N>
void run_test_case(char(&buffer)[N], const char* input, int input_size, const char* expected, F func)
{
	const auto ret = func(input, input_size, buffer, N);

	EXPECT_EQ(ret, NO_ERROR_VWC);
	EXPECT_STREQ(buffer, expected);
}
}

TEST(TestCodewarsCases, TestEncode_1) {
	const char*   input	   = "hello";
	const char*   expected = "h2ll4";

	constexpr int encoded_buf_size{ 10 };
	char          encoded[encoded_buf_size];

	run_test_case(encoded, input, static_cast<int>(strlen(input)), expected, encode_vwc);
}

TEST(TestCodewarsCases, TestEncode_2) {
	const char*   input	   = "How are you today?";
	const char*   expected = "H4w 1r2 y45 t4d1y?";

	constexpr int encoded_buf_size{ 20 };
	char          encoded[encoded_buf_size];

	run_test_case(encoded, input, static_cast<int>(strlen(input)), expected, encode_vwc);
}

TEST(TestCodewarsCases, TestEncode_3) {
	const char*   input	   = "This is an encoding test.";
	const char*   expected = "Th3s 3s 1n 2nc4d3ng t2st.";

	constexpr int encoded_buf_size{ 30 };
	char          encoded[encoded_buf_size];

	run_test_case(encoded, input, static_cast<int>(strlen(input)), expected, encode_vwc);
}

TEST(TestCodewarsCases, TestDecode_1) {
	const char*   input	   = "h2ll4";
	const char*   expected = "hello";

	constexpr int decoded_buf_size{ 10 };
	char          decoded[decoded_buf_size];

	run_test_case(decoded, input, static_cast<int>(strlen(input)), expected, decode_vwc);
}

TEST(TestCodewarsCases, TestDecode_2) {
	const char*   input    = "H4w 1r2 y45 t4d1y?";
	const char*   expected = "How are you today?";

	constexpr int decoded_buf_size{ 20 };
	char          decoded[decoded_buf_size];

	run_test_case(decoded, input, static_cast<int>(strlen(input)), expected, decode_vwc);
}

TEST(TestCodewarsCases, TestDecode_3) {
	const char*   input    = "Th3s 3s 1n 2nc4d3ng t2st.";
	const char*   expected = "This is an encoding test.";

	constexpr int decoded_buf_size{ 30 };
	char          decoded[decoded_buf_size];

	run_test_case(decoded, input, static_cast<int>(strlen(input)), expected, decode_vwc);
}
