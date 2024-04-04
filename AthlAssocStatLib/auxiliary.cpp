#include "pch.h"

#include "auxiliary.h"

using athl_assoc::api::ReturnValueException;

namespace athl_assoc
{
	ReturnValueException make_return_value_exception(const char* hint, int error_value)
	{
		constexpr unsigned BUFF_SIZE = 128;
		char error_description_buffer[BUFF_SIZE];
		const auto chars_written = sprintf_s(error_description_buffer, BUFF_SIZE, hint, error_value);
		assert(chars_written > 0);
		return api::ReturnValueException(error_value, error_description_buffer);
	}
}

