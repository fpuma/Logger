#pragma once

#include <utils/genericid.h>
#include <utils/numerictypes.h>

#include <string>

namespace puma
{
    enum class LogType
    {
        Info = 0,
        Warning,
        Error
    };

    constexpr u32 kInvalidLogCategory = kMaxU32;

    DECLARE_GENERIC_ID( LogCategory, u32, kInvalidLogCategory );

    struct CategoryInfo
    {
        LogCategory id;
        const char* name;
    };

}