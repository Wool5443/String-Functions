#include <stddef.h>

size_t StringLength(const char* string);

char* StringCopy(char* destination, const char* source, size_t maxLength);

char* StringCopyAll(char* destination, const char* source);

char* StringCat(char* destination, const char* source, size_t maxLength);

int StringCompare(const char* s1, const char* s2);

bool StringEqual(const char* s1, const char* s2, const size_t length);

char* StringFind(char* where, const char* target);

char* StringFindChar(char* where, const char goal);
