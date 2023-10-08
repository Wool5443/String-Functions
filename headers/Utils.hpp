//! @file

#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TESTINGs

/** @enum Color
 * @brief Represents colors for @see SetConsoleColor
 */
enum Color
{
    COLOR_BLACK = 30,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_MAGENTA,
    COLOR_CYAN,
    COLOR_WHITE,
};

/** @enum ErrorCode
 * @brief Represents possible error codes for @see MyAssertHard()
 */
enum ErrorCode 
{
  EVERYTHING_FINE = 0, ERROR_NULLPTR, ERROR_BAD_NUMBER, ERROR_BAD_FILE, ERROR_OVERLAP,
  ERROR_INDEX_OUT_OF_BOUNDS, ERROR_NO_MEMORY, ERROR_NO_COMPARATOR, ERROR_BAD_SIZE,
  ERROR_BAD_VALUE, ERROR_DEAD_CANARY, ERROR_BAD_HASH, ERROR_ZERO_DIVISION,
  ERROR_SYNTAX
};

static const char* ERROR_CODE_NAMES[] =
{
  "EVERYTHING_FINE", "ERROR_NULLPTR", "ERROR_BAD_NUMBER", "ERROR_BAD_FILE", "ERROR_OVERLAP",
  "ERROR_INDEX_OUT_OF_BOUNDS", "ERROR_NO_MEMORY", "ERROR_NO_COMPARATOR", "ERROR_BAD_SIZE",
  "ERROR_BAD_VALUE", "ERROR_DEAD_CANARY", "ERROR_BAD_HASH", "ERROR_ZERO_DIVISION",
  "ERROR_SYNTAX"
};

#define RETURN_ERROR(error)                                                                     \
do                                                                                              \
{                                                                                               \
   __typeof__(error) _error = error;                                                            \
   if (_error)                                                                                  \
      return _error;                                                                            \
} while (0);

/**
 * @brief Hard assert which tells the file, function and line where the error occurred.
 *
 * @param [in] STATEMENT - the condition to check.
 * @param [in] ERR_CODE - what can happen @see ErrorCode.
 * @param [in] EXIT_CMD - operation to perform before exiting the program.
 *
 * @note If there is nothing to perform pass nothing.
 */
#define MyAssertHard(STATEMENT, ERR_CODE, ...)                                                                      \
if (!(STATEMENT))                                                                                                   \
do {                                                                                                                \
    SetConsoleColor(stderr, COLOR_RED);                                                                                   \
    fprintf(stderr, "%s in %s in %s in line: %d\n", #ERR_CODE, __FILE__, __PRETTY_FUNCTION__, __LINE__);            \
    SetConsoleColor(stderr, COLOR_WHITE);                                                                                 \
    __VA_ARGS__;                                                                                                    \
    exit(ERR_CODE);                                                                                                 \
} while(0);

/**
 * @brief Transforms a given name into a string.
 * 
 * @param [in] VALUE - the thing to transform.
*/
#define ValueToString(VALUE) #VALUE

/**
 * @brief Soft assert which tells the file, function and line where the error occurred.
 *
 * @param [in] STATEMENT - the condition to check.
 * @param [in] ERR_CODE - what can happen @see ErrorCode.
 * @param [in] EXIT_CMD - operation to perform before exiting the program.
 *
 * @note If there is nothing to perform pass nothing.
 */
#define MyAssertSoft(STATEMENT, ERR_CODE, ...)                                                                      \
if (!(STATEMENT))                                                                                                   \
do {                                                                                                                \
    SetConsoleColor(stderr, COLOR_RED);                                                                                   \
    fprintf(stderr, "%s in %s in %s in line: %d\n", #ERR_CODE, __FILE__, __PRETTY_FUNCTION__, __LINE__);            \
    SetConsoleColor(stderr, COLOR_WHITE);                                                                                 \
    __VA_ARGS__;                                                                                                    \
    return ERR_CODE;                                                                                                \
} while(0);                                                                                                           \

/**
 * @brief Struct to contain where some variable was created.
 * 
 * @var Owner::fileName - the file where the variable was created.
 * @var Owner::line - the line where it was created.
 * @var Owner::name - the name of the variable.
*/
struct SourceCodePosition
{
    const char* fileName;
    size_t line;
    const char* name;
};

/**
 * @brief Tells if 2 doubles are equal.
 *
 * @param x1
 * @param x2
 *
 * @return true The numbers are equal.
 * @return false The numbers are not equal.
 */
bool IsEqual(const double x1, const double x2);

/**
 * @brief Clears stdin.
 * 
 * @param [in] where - file stream which buffer to clean.
 */
void ClearBuffer(FILE* where);

/**
 * @brief Check if the user input contains anything but scanned data.
 *
 * @param [in] where - file stream where to input.
 * 
 * @return true Everything is clear.
 * @return false User entered something odd.
 */
bool CheckInput(FILE* where);

/**
 * @brief Set the color of either stderr or stdout
 *
 * @param where - stderr or stdout
 * @param color - @see Color
 */
void SetConsoleColor(FILE* where, enum Color color);

unsigned int CalculateHash(const void *key, size_t len, unsigned int seed);

#endif