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
		std::string chunk;
		for (std::string::size_type i = 0; i < str.length(); ++i)
		{
			auto ch = str[i];
			if (separators.find(ch) == std::string_view::npos)
			{
				chunk.push_back(ch);
			}
			else if (!chunk.empty())
			{
				split.push_back(chunk);
				chunk.clear();
			}
		}
		if (!chunk.empty())
		{
			split.push_back(chunk);
		}
		return split;
	}
}

