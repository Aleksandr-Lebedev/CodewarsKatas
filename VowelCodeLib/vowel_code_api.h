#pragma once

#ifdef VOWELCODELIB_EXPORTS
#define VOWELCODELIB_API __declspec(dllexport)
#else
#define VOWELCODELIB_API __declspec(dllimport)
#endif

// https://www.codewars.com/kata/53697be005f803751e0015aa/train/cpp

typedef enum
{
	NO_ERROR_VWC                  = 0,
	INPUT_STRING_PTR_NULL_VWC     = 1,
	INPUT_STRING_LENGTH_ZERO_VWC  = 2,
	OUTPUT_STRING_PTR_NULL_VWC    = 3,
	OUTPUT_STRING_LENGTH_ZERO_VWC = 4,
	STRINS_SIZES_TO_LOWER_VWC     = 5,
	INTERNAL_ERROR_VWC            = 6
} ENCODE_RESULT_VWC;

int VOWELCODELIB_API encode_vwc(const char* const origin, int origin_size, char* encoded, int encoded_size);

int VOWELCODELIB_API decode_vwc(const char* const encoded, int encoded_size, char* decoded, int decoded_size);
