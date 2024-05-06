#pragma once
#include "library_declspec.h"

namespace athl_assoc
{
	class ATHLASSOCSTATLIB_API TimeResult
	{
	public:
		TimeResult(unsigned h, unsigned m, unsigned s) noexcept
			: _hours(h)
			, _minutes(m)
			, _seconds(s)
		{}

		static TimeResult from_str(std::string_view tm_result_strv);

		unsigned Hours() const noexcept
		{
			return _hours;
		}

		unsigned Minutes() const noexcept
		{
			return _minutes;
		}

		unsigned Seconds() const noexcept
		{
			return _seconds;
		}

	private:
		TimeResult() = default;

		unsigned _hours;
		unsigned _minutes;
		unsigned _seconds;
	};
}

