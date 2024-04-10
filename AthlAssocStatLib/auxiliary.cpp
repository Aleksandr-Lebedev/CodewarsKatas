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
		// std::string::size_type left = 0;
		// for (auto right = str.find_first_of(separators, left); right != std::string::npos && left != std::string::npos;)
		// {
		// 	split.emplace_back(str.substr(left, right));
		// 	left += right;
		// 	if (left < str.length())
		// 	{
		// 		left = str.find_first_not_of(separators, left);
		// 	}
		// 	else
		// 	{
		// 		break;
		// 	}
		// }
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

