//! @file

#include <stddef.h>

#ifndef STRING_FUNTCIONS_HPP
#define STRING_FUNTCIONS_HPP

/**
 * @brief Counts the lenght of a null terminated string.
 *
 * @param [in] string - the string to find the length of.
 *
 * @return size_t length of the string.
*/
size_t StringLength(const char* string);

/**
 * @brief Copies the source to the destination.
 * Safe becuase destination length must be given.
 *
 * @param [in, out] destination - where to copy.
 * @param [in] source - from where to copy.
 * @param [in] maxLength - how many elements destination can store.
 *
 * @return char* to destination.
*/
char* StringCopy(char* destination, const char* source, size_t maxLength);

/**
 * @brief Copies the entire source into destination.
 * Unsafe.
 *
 * @param [in, out] destination - where to copy.
 * @param [in] source - from where to copy.
 *
 * @return char* to destination.
*/
char* StringCopyAll(char* destination, const char* source);

/**
 * @brief Concatinate destination and source.
 * Safe becuase length of destination is given.
 *
 * @param [in, out] destination - the string to append to.
 * @param [in] source - from where to append.
 * @param [in] maxLength - destination size.
 *
 * @return char* to destination.
*/
char* StringCat(char* destination, const char* source, size_t maxLength);

/**
 * @brief Compares 2 strings and return which is bigger.
 *
 * @param [in] s1, s2 - strings to compare.
 *
 * @return >0 - s1 is bigger.
 * @return - equal.
 * @return <0 - s2 is bigger.
*/
int StringCompare(const char* s1, const char* s2);

/**
 * @brief Compares length elements of the strings and returns if they are equal.
 *
 * @param [in] s1, s2 - the strings to compare.
 * @param [in] length - the amount of characters to compare.
 *
 * @return true - equal.
 * @return false - inequal.
*/
bool StringEqual(const char* s1, const char* s2, const size_t length);

/**
 * @brief Finds the target substring in where and returns the pointer to it in where.
 *
 * Uses shift algorithm.
 *
 * @param [in] where - the string to find in.
 * @param [in] target - the string to find.
 *
 * @return char* to the target substring in destination.
*/
const char* StringFind(const char* where, const char* target);

/**
 * @brief Finds char target in where and return a pointer to its location.
 *
 * @param [in] where - the string to find the target in.
 * @param [in] target - the char to find.
 *
 * @return char* to the first occurence of target in where.
*/
const char* StringFindChar(const char* where, const char target);

#endif
