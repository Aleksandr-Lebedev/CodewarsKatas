#pragma once

#include "library_declspec.h"
#include "return_codes.h"

// https://www.codewars.com/kata/55b3425df71c1201a800009c

/// @brief Calculate race statistics.
///
/// If the output c-string is not large enough to contain the entire calculation result
/// then the result string will be truncated.
/// 
/// @param[in] race_results_cstr a pointer to a race results c-string
/// @param[out] race_stats_out_buf a pointer to an allocated c-string for the calculation results or a null pointer
/// @param[in,out] race_stats_out_buf_length a pointer to the variable length of the output buffer.
/// @return zero in case of success or an error code.
int ATHLASSOCSTATLIB_API calculate_race_statistics(const char* const race_results_cstr, char* race_stats_out_buf, int* race_stats_out_buf_length);

/// Returns the maximum number of character in a race results string without a null terminator
int ATHLASSOCSTATLIB_API race_results_str_max_length();

/// Returns a string represantion of the last error if any
ATHLASSOCSTATLIB_API
const char* get_last_error_msg_cstr();

