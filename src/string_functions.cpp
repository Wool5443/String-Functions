#include "string_functions.hpp"
#include "utils.hpp"

const int INCLUDE_NULL_TERMINATOR_FIX = 1, FOUND_STRING = -1, ALPHABET_LENGTH = 256;

int findShift(const char* where, const char* target, const size_t place, const size_t targetLength);

size_t StringLength(const char* string)
{
    MyAssertHard(string, ERROR_NULLPTR, );

    size_t length = 0;
    while (*(string++) != '\0')
        length++;

    return length;
}

char* StringCopy(char* destination, const char* source, size_t maxLength)
{
    MyAssertHard(destination, ERROR_NULLPTR, );
    MyAssertHard(source, ERROR_NULLPTR, );

    size_t sourceLength = StringLength(source);
    size_t numOfElToCopy = min(sourceLength, maxLength - INCLUDE_NULL_TERMINATOR_FIX);

    MyAssertHard(destination + maxLength <= source
        || source + sourceLength < destination,
        ERROR_OVERLAP,
        );

    for (size_t i = 0; i < numOfElToCopy; i++)
        destination[i] = source[i];

    destination[numOfElToCopy] = '\0';

    return destination;
}

char* StringCopyAll(char* destination, const char* source)
{
    MyAssertHard(destination, ERROR_NULLPTR, );
    MyAssertHard(source, ERROR_NULLPTR, );

    size_t sourceLength = StringLength(source);

    MyAssertHard(destination + sourceLength < source
        || source + sourceLength < destination,
        ERROR_OVERLAP,
        );

    for (size_t i = 0; i < sourceLength; i++)
        destination[i] = source[i];

    return destination;
}

char* StringCat(char* destination, const char* source, size_t maxLength)
{
    MyAssertHard(destination, ERROR_NULLPTR, );
    MyAssertHard(source, ERROR_NULLPTR, );

    size_t destinationLength = StringLength(destination);

    return StringCopy(destination + destinationLength, source, maxLength - destinationLength) - destinationLength;
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

    size_t shifts[ALPHABET_LENGTH] = {};

    for (size_t i = 0; i < ArrayLength(shifts); i++)
        shifts[i] = targetLength;

    for (size_t i = 2; i < targetLength + 1; i++)
    {
        int c = target[targetLength - i];
        shifts[c] = min(shifts[c], i - 1);
    }

    size_t place = 0;

    while (place + targetLength - 1 < whereLength)
    {
        int shiftChar = findShift(where, target, place, targetLength);
        if (shiftChar == FOUND_STRING)
            return where + place;
        place += shifts[shiftChar];
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
    MyAssertHard(where, ERROR_NULLPTR, );
    MyAssertHard(target, ERROR_NULLPTR, );

    for (size_t i = 0; i < targetLength; i++)
        if (where[place + targetLength - 1 - i] != target[targetLength - 1 - i])
            return where[place + targetLength - 1 - i];
    return FOUND_STRING;
}
