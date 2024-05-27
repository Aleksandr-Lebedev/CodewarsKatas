#pragma once

#include "return_codes.h"

#include <map>
#include <string>

inline const char* get_return_code_default_msg(COMMON_RET_CODES ret_code) noexcept
{
	static const std::map<COMMON_RET_CODES, std::string> ret_codes_msgs {
		{ COMMON_NO_ERROR, "No error" },
		{ ARGUMENT_NULLPTR, "Argument pointer is null" },
		{ INPUT_STRING_INVALID, "Input string is invalid" },
		{ INPUT_STRING_LENGTH_ZERO, "Input string length is zero" },
		{ INPUT_STRING_NULLPTR, "Input string pointer is null" },
		{ OUTPUT_STRING_INVALID, "Output string is invalid" },
		{ OUTPUT_STRING_LENGTH_ZERO, "Output string length is zero" },
		{ OUTPUT_STRING_NULLPTR, "Output string pointer is null" },
		{ STRINS_SIZE_TOO_LOWER, "String length is too lower" },
		{ EXCEPTION_THROWN, "An exception has been thrown" },
		{ OTHER_ERROR, "Other error" },
		{ MODULE_INTERNAL_ERR0R, "Module internal error"}
	};

	const auto msg_iter = ret_codes_msgs.find(ret_code);
	if (msg_iter == ret_codes_msgs.cend())
	{
		return "Unknown error code";
	}

	return msg_iter->second.c_str();
}

