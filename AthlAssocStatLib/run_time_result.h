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
			, _total_seconds(0)
		{
			reset_total_seconds();
		}
		
		TimeResult()
			: _hours(0)
			, _minutes(0)
			, _seconds(0)
			, _total_seconds(0)

		{}

		TimeResult(unsigned total_seconds) noexcept
			: _hours(0)
			, _minutes(0)
			, _seconds(0)
			, _total_seconds(total_seconds)

		{
			reset_hms();
		}

		TimeResult(const TimeResult&) noexcept            = default;
		TimeResult& operator=(const TimeResult&) noexcept = default;

		static TimeResult from_str(std::string_view tm_result_strv);

		std::string to_str()                        const noexcept;
		std::string to_str(std::string_view prefix) const noexcept;

		static constexpr unsigned SECONDS_IN_MINUTE = 60;
		static constexpr unsigned SECONDS_IN_HOURS  = 3600;

		bool       operator<(const TimeResult& rhs) const noexcept;
		TimeResult operator-(const TimeResult& rhs) const noexcept;
		TimeResult operator+(const TimeResult& rhs) const noexcept;

		void divide(unsigned denominator);

		unsigned hours() const noexcept
		{
			return _hours;
		}

		unsigned minutes() const noexcept
		{
			return _minutes;
		}

		unsigned seconds() const noexcept
		{
			return _seconds;
		}

	private:
		void reset_total_seconds() noexcept
		{
			_total_seconds = _seconds + _minutes * SECONDS_IN_MINUTE + _hours * SECONDS_IN_HOURS;
		}

		void reset_hms() noexcept;

		unsigned _hours;
		unsigned _minutes;
		unsigned _seconds;
		unsigned _total_seconds;
	};
}

