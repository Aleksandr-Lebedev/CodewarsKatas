#include "pch.h"

#include "athl_assoc_stat_api.h"
#include "calculate_stats.h"
#include "error_message.h"

using athl_assoc::ErrorMessage;

namespace
{
inline int search_null_term(const char* const cstr, int max_offset)
{
    for (int offset = 0; offset < max_offset; ++offset)
    {
        if (cstr[offset] == '\0')
        {
            return offset;
        }
    }
    return max_offset;
}
}

int calculate_race_statistics(const char* const race_results_cstr, char* race_stats_out_buf, int* race_stats_out_buf_length)
{
    try
    {
        const auto max_results_cstr_length = athl_assoc::MAX_CSTRING_LENGTH + 1;

        if (race_results_cstr == nullptr)
        {
            ErrorMessage::instance()->store_msg("'race_results_cstr' pointer is null");
            return INPUT_STRING_NULLPTR;
        }

        if (search_null_term(race_results_cstr, max_results_cstr_length + 1) > max_results_cstr_length)
        {
            ErrorMessage::instance()->store_msg("'race_results_cstr' doesn't contain a termination null character");
            return INPUT_STRING_INVALID;
        }

        if (race_stats_out_buf_length == nullptr)
        {
            ErrorMessage::instance()->store_msg("'race_stats_out_buf_length' pointer is null");
            return ARGUMENT_NULLPTR;
        }

        // Copy of elements into dynamic memory. This was done here only because the original task required
        // us to pass the first argument as a c-ref to the std::string.
        std::string race_results(race_results_cstr);
        auto stats = athl_assoc::calculate_statistics(race_results);
        const auto stats_length = static_cast<int>(stats.length());
        if (*race_stats_out_buf_length < stats_length + 1)
        {
            return STRING_SIZE_TOO_LOWER;
        }
        if (race_stats_out_buf != nullptr && *race_stats_out_buf_length > 0)
        {
            if (strncpy_s(race_stats_out_buf, *race_stats_out_buf_length, stats.c_str(), stats_length))
            {
                ErrorMessage::instance()->store_msg("An attempt to write statistics to the output buffer failed.");
                return OTHER_ERROR;
            }
        }

        *race_stats_out_buf_length = stats_length;
    }
    catch (std::invalid_argument& error)
    {
        ErrorMessage::instance()->store_msg(error.what());
        return INPUT_STRING_INVALID;
    }
    catch (std::exception& error)
    {
        ErrorMessage::instance()->store_msg(error.what());
        return EXCEPTION_THROWN;
    }
    return COMMON_NO_ERROR;
}

int race_results_str_max_length()
{
    return athl_assoc::MAX_CSTRING_LENGTH;
}

const char* get_last_error_msg_cstr()
{
    return ErrorMessage::instance()->get_msg();
}

