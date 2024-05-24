#include "pch.h"
#include "error_message.h"
#include "return_codes.h"

namespace athl_assoc
{
	void ErrorMessage::store_msg(int error_code) noexcept
	{
		switch (error_code)
		{
		case COMMON_NO_ERROR:
			_error_msg = "No error";
			break;
		case ARGUMENT_NULLPTR:
			_error_msg = "Argument pointer is null";
			break;
		case INPUT_STRING_INVALID:
			_error_msg = "Input string is invalid";
			break;
		case INPUT_STRING_LENGTH_ZERO:
			_error_msg = "Input string length is zero";
			break;
		case INPUT_STRING_PTR_NULL:
			_error_msg = "Input string pointer is null";
			break;
		case OUTPUT_STRING_INVALID:
			_error_msg = "Output string is invalid";
			break;
		case OUTPUT_STRING_LENGTH_ZERO:
			_error_msg = "Output string length is zero";
			break;
		case OUTPUT_STRING_PTR_NULL:
			_error_msg = "Output string pointer is null";
			break;
		case STRINS_SIZE_TO_LOWER:
			_error_msg = "String length is too lower";
			break;
		case EXCEPTION_THROWN:
			_error_msg = "An exception has been thrown";
			break;
		case OTHER_ERROR:
			_error_msg = "Other error";
			break;
		case MODULE_INTERNAL_ERR0R:
			_error_msg = "Module internal error";
			break;
		default:
			_error_msg = "Unknown error code";
			break;
		}
	}
}

