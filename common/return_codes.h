#pragma once

typedef enum
{
	COMMON_NO_ERROR           = 0x0,
	ARGUMENT_NULLPTR,
	INPUT_STRING_INVALID,
	INPUT_STRING_LENGTH_ZERO,
	INPUT_STRING_NULLPTR,
	OUTPUT_STRING_INVALID,
	OUTPUT_STRING_LENGTH_ZERO,
	OUTPUT_STRING_NULLPTR,
	STRINS_SIZE_TOO_LOWER,
	EXCEPTION_THROWN,
	OTHER_ERROR               = 0xe,
	MODULE_INTERNAL_ERR0R     = 0xf
} COMMON_RET_CODES;

