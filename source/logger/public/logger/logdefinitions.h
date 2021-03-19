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

    class LogCategory : public GenericID<u32, kInvalidLogCategory>
    {
    public:
        LogCategory() {}
        LogCategory( u32 _id )
            : GenericID( _id )
        {}
    };

    struct CategoryInfo
    {
        LogCategory id;
        const char* name;
    };

}