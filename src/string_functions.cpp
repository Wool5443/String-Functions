#include <assert.h>
#include "string_functions.hpp"
#include "utils.hpp"

const int INCLUDE_0_FIX = 1;

size_t StringLength(const char* string)
{
    MyAssertHard(string, ERROR_NULLPTR, );

    size_t length = 0;
    while (*(string++) != '\0')
    {
        length++;
    }

    return length;
}

char* StringCopy(char* destination, const char* source, size_t maxLength)
{
    size_t sourceLength = StringLength(source) + INCLUDE_0_FIX;

    MyAssertHard(destination + min(sourceLength, maxLength) <= source || source + sourceLength <= destination
        , ERROR_INDEX_OUT_OF_BOUNDS, );

    for (size_t i = 0; i < min(sourceLength, maxLength); i++)
    {
        destination[i] = source[i];
    }

    if (sourceLength > maxLength)
        destination[maxLength - 1] = '\0';


    return destination;
}

char* StringCopyAll(char* destination, const char* source)
{
    size_t sourceLength = StringLength(source);

    MyAssertHard(destination + sourceLength < source
        || source + sourceLength < destination
        , ERROR_INDEX_OUT_OF_BOUNDS, );

    for (size_t i = 0; i < sourceLength; i++)
    {
        destination[i] = source[i];
    }

    return destination;
}

bool StringCompare(const char* s1, const char* s2)
{
    size_t s1Length = StringLength(s1);

    if (s1Length != StringLength(s2))
        return false;

    for (size_t i = 0; i < s1Length; i++)
        if (s1[i] != s2[i])
            return false;

    return true;
}
