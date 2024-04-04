#pragma once

#include <stdexcept>

namespace athl_assoc::api
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

	class ReturnValueException : public std::runtime_error
	{
	public:
		ReturnValueException(int error_value, const std::string& what_arg)
			: std::runtime_error(what_arg)
			, _error_value(error_value)
		{}

		ReturnValueException(int error_value, const char* what_arg)
			: std::runtime_error(what_arg)
			, _error_value(error_value)
		{}

		int error_value() const noexcept
		{
			return _error_value;
		}

	private:
		int _error_value;
	};
}

