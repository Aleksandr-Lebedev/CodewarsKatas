#pragma once

#include <stdexcept>

namespace athl_assoc
{
	/// @class ParseError
	/// @brief This exception indicates an error occurred while parsing a string
	class ParseError: public std::runtime_error
	{
	public:
		explicit ParseError(const std::string& what_arg)
			: std::runtime_error(what_arg)
		{}

		explicit ParseError(const char* what_arg)
			: std::runtime_error(what_arg)
		{}
	};
}

