#pragma once

#ifdef ATHLASSOCSTATLIB_EXPORTS
#define ATHLASSOCSTATLIB_API __declspec(dllexport)
#else
#define ATHLASSOCSTATLIB_API  __declspec(dllimport)
#endif

// https://www.codewars.com/kata/55b3425df71c1201a800009c
namespace athl_assoc
{
	/// @brief Calculate race statistics.
	///
	/// If the output c-string is not large enough to contain the entire calculation result
	/// then the result string will be truncated.
	/// 
	/// @param[in] race_results_cstr a pointer to a race results c-string
	/// @param[in] race_results_cstr_length a number of characters in the rase results c-string
	/// @param[out] race_stats_cstr a pointer to an allocated c-string for the calculation results or a null pointer
	/// @param[in] race_stats_cstr_length a length of the output c-string in characters 
	/// @return the new number of characters in race stats output c-string
	/// @exception std::invalid_argument if race_resultes_cstr is a null pointer
	/// @exception std::length_error if race_resutls_cstr_length is equals to zero
	/// @exception athl_assoc::ParseError in case if race_resutls_cstr parse failed
	[[nodiscard]]
	int ATHLASSOCSTATLIB_API calculate_race_statistics(const char* const race_results_cstr, int race_results_cstr_length, char* race_stats_cstr, int race_stats_cstr_length);
}

