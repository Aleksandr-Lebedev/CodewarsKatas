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

	std::vector<std::string> split_string(const std::string& str, std::string_view separators)
	{
		std::vector<std::string> split;
		auto left_it = str.begin();
		auto right_it = std::find_first_of(left_it, str.end(), separators.cbegin(), separators.cend());
		while (left_it != right_it)
		{
			split.emplace_back(left_it, right_it);
			left_it = std::find_first_of(right_it, str.end(), separators.cbegin(), separators.cend(), [](char ch, char sp)
				{
					return ch != sp;
				});
			right_it = std::find_first_of(left_it, str.end(), separators.cbegin(), separators.cend());
		}
		return split;
	}
}

