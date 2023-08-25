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
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 < *s2)
            return LESS;
        if (*s1 > *s2)
            return MORE;

        s1++;
        s2++;
    }

    if (*s1 < *s2)
        return LESS;
    if (*s1 > *s2)
        return MORE;

    return EQAUL;
}

bool StringEqual(const char* s1, const char* s2, const size_t length)
{
    size_t s1Length = StringLength(s1);
    size_t s2Length = StringLength(s2);

    if (s1Length < length || s2Length < length)
        return false;

    for (size_t i = 0; i < length; i++)
        if (s1[i] != s2[i])
            return false;

    return true;
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

char* StringFind(char* where, const char* goal)
{
    size_t whereLength = StringLength(where);
    size_t goalLength = StringLength(goal);

    if (whereLength < goalLength)
        return NULL;

    for (size_t i = 0; i + goalLength - 1 < whereLength; i++)
        if (StringEqual(where + i, goal, goalLength))
            return where + i;

    return NULL;
}

char* StringFindChar(char* where, const char goal)
{
    while (*where != '\0')
    {
        if (*where == goal)
            return where;
        where++;
    }

    return NULL;
}
