#pragma once

#include "custom_exceptions.h"

namespace athl_assoc
{
	api::ReturnValueException make_return_value_exception(const char* hint, int error_value);

	std::vector<std::string> split_string(const std::string& str, char delim);
}

