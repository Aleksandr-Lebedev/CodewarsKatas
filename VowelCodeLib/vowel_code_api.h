#pragma once

#include "return_codes.h"

#ifdef VOWELCODELIB_EXPORTS
#define VOWELCODELIB_API __declspec(dllexport)
#else
#define VOWELCODELIB_API __declspec(dllimport)
#endif

// https://www.codewars.com/kata/53697be005f803751e0015aa/train/cpp

extern "C"
{
	int VOWELCODELIB_API encode_vwc(const char* const origin, int origin_size, char* encoded, int encoded_size);

	int VOWELCODELIB_API decode_vwc(const char* const encoded, int encoded_size, char* decoded, int decoded_size);
}

