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

CompareResult StringCompare(const char* s1, const char* s2)
{
    while (*s1 != '\0' || *s2 != '\0')
    {
        if (*s1 < *s2)
            return LESS;
        if (*s1 > *s2)
            return MORE;

        s1++;
        s2++;
    }

    return EQAUL;
}

char* StringCat(char* destination, const char* source)
{
    while (*destination != '\0')
        destination++;

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = *source;

    return destination;
}
