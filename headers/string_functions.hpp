enum CompareResult { LESS = -1, EQAUL = 0, MORE = 1 };

size_t StringLength(const char* string);

char* StringCopy(char* destination, const char* source, size_t maxLength);

char* StringCopyAll(char* destination, const char* source);

CompareResult StringCompare(const char* s1, const char* s2);

char* StringCat(char* destination, const char* source);
