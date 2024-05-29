#include "pch.h"

#include "encode.h"
#include "vowel_code_api.h"

using namespace CodewarsKatas;

static int check_args(const char* const input, int input_size, const char* const output, int output_size)
{
	if (input == nullptr)
		return INPUT_STRING_NULLPTR;

	if (input_size == 0)
		return INPUT_STRING_LENGTH_ZERO;

	if (output == nullptr)
		return OUTPUT_STRING_NULLPTR;

	if (output_size == 0)
		return OUTPUT_STRING_LENGTH_ZERO;

	if (input_size > output_size)
		return STRING_SIZE_TOO_LOWER;

	return COMMON_NO_ERROR;
}

int encode_vwc(const char* const origin, int origin_size, char* encoded, int encoded_size)
{
	const auto check_result = check_args(origin, origin_size, encoded, encoded_size);
	if (check_result != COMMON_NO_ERROR)
		return check_result;

	const auto result = VowelCodeLib::encode(origin);
	if (strncpy_s(encoded, encoded_size, result.c_str(), result.size()) != 0)
		return OTHER_ERROR;

	return COMMON_NO_ERROR;
}

int decode_vwc(const char* const encoded, int encoded_size, char* decoded, int decoded_size)
{
	const auto check_result = check_args(encoded, encoded_size, decoded, decoded_size);
	if (check_result != COMMON_NO_ERROR)
		return check_result;

	const auto result = VowelCodeLib::decode(encoded);
	if (strncpy_s(decoded, decoded_size * sizeof(char), result.c_str(), result.size()) != 0)
		return OTHER_ERROR;

	return COMMON_NO_ERROR;
}

