#include <assert.h>
#include "string_functions.hpp"
#include "utils.hpp"

constexpr int INCLUDE_NTRM_FIX = 1, SCHAR_TO_UCHAR = 128, FOUND_STRING = -1;

int findShift(const char* where, const char* target, const size_t place, const size_t targetLength);

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
    MyAssertHard(destination, ERROR_NULLPTR, );
    MyAssertHard(source, ERROR_NULLPTR, );

    size_t sourceLength = StringLength(source) + INCLUDE_NTRM_FIX;

    MyAssertHard(destination + min(sourceLength, maxLength) <= source
        || source + sourceLength <= destination, ERROR_OVERLAP, );

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
    MyAssertHard(destination, ERROR_NULLPTR, );
    MyAssertHard(source, ERROR_NULLPTR, );

    size_t sourceLength = StringLength(source);

    MyAssertHard(destination + sourceLength < source || source + sourceLength < destination, ERROR_OVERLAP, );

    for (size_t i = 0; i < sourceLength; i++)
    {
        destination[i] = source[i];
    }

    return destination;
}

char* StringCat(char* destination, const char* source, size_t maxLength)
{
    MyAssertHard(destination, ERROR_NULLPTR, );
    MyAssertHard(source, ERROR_NULLPTR, );

    size_t destinationLength = StringLength(destination);

    return StringCopy(destination + destinationLength, source, maxLength - (destinationLength));
}

int StringCompare(const char* s1, const char* s2)
{
    MyAssertHard(s1, ERROR_NULLPTR, );
    MyAssertHard(s2, ERROR_NULLPTR, );

    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

bool StringEqual(const char* s1, const char* s2, const size_t length)
{
    MyAssertHard(s2, ERROR_NULLPTR, );
    MyAssertHard(s1, ERROR_NULLPTR, );

    size_t s1Length = StringLength(s1);
    size_t s2Length = StringLength(s2);

    if (s1Length < length || s2Length < length)
        return false;

    for (size_t i = 0; i < length; i++)
        if (s1[i] != s2[i])
            return false;

    return true;
}

char* StringFind(char* where, const char* target)
{
    MyAssertHard(where, ERROR_NULLPTR, );
    MyAssertHard(target, ERROR_NULLPTR, );

    size_t whereLength = StringLength(where);
    size_t targetLength = StringLength(target);
    if (whereLength < targetLength)
        return NULL;

    size_t whereSum = 0, targetSum = 0;
    for (size_t i = 0; i < targetLength; i++)
    {
        whereSum += (size_t)where[i];
        targetSum += (size_t)target[i];
    }

    for (size_t i = 0; i + targetLength - 1 < whereLength; i++)
    {
        if (whereSum == targetSum && StringEqual(where + i, target, targetLength))
            return where + i;

        whereSum += (size_t)where[i + targetLength];
        whereSum -= (size_t)where[i];
    }

    return NULL;
}

char* StringFind2(char* where, const char* target)
{
    MyAssertHard(where, ERROR_NULLPTR, );
    MyAssertHard(target, ERROR_NULLPTR, );

    size_t whereLength = StringLength(where);
    size_t targetLength = StringLength(target);
    if (whereLength < targetLength)
        return NULL;

    size_t shifts[256] = {};
    shifts[target[targetLength - 1 + SCHAR_TO_UCHAR]] = targetLength;

    for (size_t i = 2; i < targetLength - 1; i++)
    {
        int c = target[targetLength - i] + SCHAR_TO_UCHAR;
        shifts[c] = min(shifts[c], i - 1);
    }

    for (int i = 0; i < )

        size_t place = 0;

    while (place + targetLength - 1 < whereLength)
    {
        int shiftC = findShift(where, target, place, targetLength);
        if (shiftC == FOUND_STRING)
            return where + place;
        place += shifts[shiftC];
    }

    return NULL;
}

char* StringFindChar(char* where, const char target)
{
    MyAssertHard(where, ERROR_NULLPTR, );

    while (*where != '\0')
    {
        if (*where == target)
            return where;
        where++;
    }

    return NULL;
}

int findShift(const char* where, const char* target, const size_t place, const size_t targetLength)
{
    for (size_t i = targetLength - 1; i >= 0; i--)
        if (where[place + i] != target[i])
            return where[place + i] + SCHAR_TO_UCHAR;
    return FOUND_STRING;
}
