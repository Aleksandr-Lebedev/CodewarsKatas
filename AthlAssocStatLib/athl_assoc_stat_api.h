#pragma once

#include "library_declspec.h"

// https://www.codewars.com/kata/55b3425df71c1201a800009c
namespace athl_assoc::api
{
	/// @brief Calculate race statistics.
	///
	/// If the output c-string is not large enough to contain the entire calculation result
	/// then the result string will be truncated.
	/// 
	/// @param[in] race_results_cstr a pointer to a race results c-string
	/// @param[out] race_stats_out_buf a pointer to an allocated c-string for the calculation results or a null pointer
	/// @param[in] race_stats_out_buf_length a length of the output c-string in characters 
	/// @return the new number of characters in race stats output c-string
	/// @exception std::invalid_argument if race_resultes_cstr is a null pointer.
	///            Alse this exception will be thrown in case if the rase resutls c-string is
	///            too long or doesn't contains a null terminator.
	/// @exception athl_assoc::ParseError in case if race_resutls_cstr parse failed
	[[nodiscard]]
	int ATHLASSOCSTATLIB_API calculate_race_statistics(const char* const race_results_cstr, char* race_stats_out_buf, int race_stats_out_buf_length);

	/// Returns the maximum number of character in a race results string without a null terminator
	int ATHLASSOCSTATLIB_API race_results_str_max_length() noexcept;
}

