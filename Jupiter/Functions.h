/**
 * Copyright (C) 2013-2014 Justin James.
 *
 * This license must be preserved.
 * Any applications, libraries, or code which make any use of any
 * component of this program must not be commercial, unless explicit
 * permission is granted from the original author. The use of this
 * program for non-profit purposes is permitted.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * In the event that this license restricts you from making desired use of this program, contact the original author.
 * Written by Justin James <justin.aj@hotmail.com>
 */

#if !defined _FUNCTIONS_H_HEADER
#define _FUNCTIONS_H_HEADER

#include "Jupiter.h"
#define ENDL "\r\n"
#define WHITESPACE " \t"

/**
 * @file Functions.h
 * @brief Provides some functions to be used at your convenience.
 */

#if defined __cplusplus

#include <cstdint>

namespace Jupiter
{
	/**
	* @brief Returns the length of a C-style string.
	* This will often get optimized by the compiler such that the calculation time is 0.
	*
	* @param str C-style string to get the length of.
	* @return Length of the C-style string.
	*/
	template<typename T = char> inline size_t strlen(const T *str);

	/**
	* @brief Copies a string of elements from one buffer to another.
	* Note: The destination buffer must be at least as long as the source + 1.
	*
	* @param dest Destination buffer for the string of elements.
	* @param source Buffer containing the source elements.
	* @return Pointer to the destination.
	*/
	template<typename T = char> inline T *strcpy(T *dest, const T *source);

	/**
	* @brief Copies a string of elements from one buffer to another.
	* Note: The destination buffer must be at least as long as sourceLength + 1.
	*
	* @param dest Destination buffer for the string of elements.
	* @param source Buffer containing the source elements.
	* @param sourceLength Number of elements to copy, excluding null-terminator.
	* @return Pointer to the destination.
	*/
	template<typename T = char> inline T *strcpy(T *dest, const T *source, size_t sourceLength);

	/**
	* @brief Returns a pointer to the first occurance of an element from str2 appearing in str1, or nullptr.
	* Note: The destination buffer must be at least as long as sourceLength + 1.
	*
	* @param str1 String to be scanned.
	* @param str2 String containing elements to find.
	* @return Pointer to the first instance of a character in str2 being in str1, or nullptr if there is none.
	*/
	template<typename T = char> inline const T *strpbrk(const T *str1, const T *str2);
	template<typename T = char> inline const T *strpbrk(const T *str1, const T str2);

	/**
	* @brief Checks if two strings are equal.
	*
	* @param str1 String to be compared.
	* @param str2 String to be compared.
	* @return True if the strings are equal, false otherwise.
	*/
	template<typename T = char> bool streql(const T *str1, const T *str2);
}

extern "C"
{
#else // __cplusplus
#include <stdbool.h>
#include <stdint.h>
#endif // __cplusplus

/**
* @brief Case insensitive version of strstr().
*
* @param str1 String to be scanned.
* @param str2 String to be matched.
* @return Pointer to the first occurance of str2 in str1 if it exists, NULL otherwise.
*/
JUPITER_API const char *stristr(const char *str1, const char *str2);

/**
* @brief Returns the length of a C-style string.
*
* @param str C-style string to get the length of.
* @return Length of the C-style string.
*/
JUPITER_API size_t Jupiter_strlen(const char *str);

/**
* @brief Returns the length of a C-style string.
*
* @param str C-style string to get the length of.
* @return Length of the C-style string.
*/
JUPITER_API size_t Jupiter_wstrlen(const wchar_t *str);

/**
* @brief Returns the length of a C-style string.
*
* @param str C-style string to get the length of.
* @return Length of the C-style string.
*/
JUPITER_API size_t Jupiter_strlen8(const uint8_t *str);

/**
* @brief Returns the length of a C-style string.
*
* @param str C-style string to get the length of.
* @return Length of the C-style string.
*/
JUPITER_API size_t Jupiter_strlen16(const uint16_t *str);

/**
* @brief Returns the length of a C-style string.
*
* @param str C-style string to get the length of.
* @return Length of the C-style string.
*/
JUPITER_API size_t Jupiter_strlen32(const uint32_t *str);

/**
* @brief Returns the length of a C-style string.
*
* @param str C-style string to get the length of.
* @return Length of the C-style string.
*/
JUPITER_API size_t Jupiter_strlen64(const uint64_t *str);

/**
* @brief Returns the length of a C-style string.
*
* @param str C-style string to get the length of.
* @return Length of the C-style string.
*/
JUPITER_API size_t Jupiter_vstrlen(const void *str, size_t size);

/**
* @brief Checks if two strings are equal. This function is case-sensitive.
*
* @param str1 String to be compared.
* @param str2 String to be compared.
* @return True if the strings are equal, false otherwise.
*/
JUPITER_API bool streql(const char *str1, const char *str2);
JUPITER_API bool wstreql(const wchar_t *str1, const wchar_t *str2);

/**
* @brief Checks if two strings are equal. This function is not case-sensitive.
*
* @param str1 String to be compared.
* @param str2 String to be compared.
* @return True if the strings are equal, false otherwise.
*/
JUPITER_API bool streqli(const char *str1, const char *str2);
JUPITER_API bool wstreqli(const wchar_t *str1, const wchar_t *str2);

/**
* @brief Checks if a string matches a wildcard format.
* Note: Case sensitive.
*
* @param format Sring containing the wildcard format information.
* @param str2 String to be compared.
* @return True if the string matches the wildcard format, false otherwise.
*/
JUPITER_API bool strmatch(const char *format, const char *str);
JUPITER_API bool wstrmatch(const wchar_t *format, const wchar_t *str);

/**
* @brief Checks if a string matches a wildcard format.
* Note: Case insensitive.
*
* @param format Sring containing the wildcard format information.
* @param str2 String to be compared.
* @return True if the string matches the wildcard format, false otherwise.
*/
JUPITER_API bool strmatchi(const char *format, const char *str);
JUPITER_API bool wstrmatchi(const wchar_t *format, const wchar_t *str);

/**
* @brief Returns a copy of a substring.
*
* @param str String 
* @param a String to be compared.
* @param b String to be compared.
* @return String containing the substring, or NULL on malloc failure.
*/
JUPITER_API char *charToChar(const char *str, int a, int b);
JUPITER_API wchar_t *wcharToChar(const wchar_t *str, int a, int b);

/**
* @brief Removes any carriage-returns (\r) and new lines (\n) from a string.
*
* @param str String to be trimed.
*/
JUPITER_API void trim(char *str);

/**
* @brief Returns a copy of a "word" from a string.
*
* @param str String to be parsed.
* @param w Position of the word, starting at 0.
* @return String containing the word on success, or NULL otherwise.
*/
JUPITER_API char *getWord(const char *str, int w);

/**
* @brief Returns the number of occurances of a given character.
*
* @param str String to be scanned.
* @param c Character to be counted.
* @return Total number of occurances of a character in a string.
*/
JUPITER_API unsigned int countSymbol(const char *str, char c);

/**
* @brief Returns the number of space-deliminated words in a string.
*
* @param str String to be scanned.
* @return Total number of space-deliminated words in a string.
*/
JUPITER_API unsigned int wordCount(const char *str);

/**
* @brief Returns the number of newlines in a string.
*
* @param str String to be scanned.
* @return Total number of newlines in a string.
*/
JUPITER_API unsigned int countLines(const char *str);

/**
* @brief Returns a substring in the form of a new String,
*
* @param str String to be scanned.
* @return String representing a single line of the input string on success, NULL otherwise.
*/
JUPITER_API char *getLine(const char *str, unsigned int l);

/**
* @brief Returns the position of the n'th occurance of a character in a string.
*
* @param str String to be scanned.
* @param c Character to find.
* @param n Position of the character to search for.
* @return Position of the n'th occurance of a character if it exists, -1 otherwise.
*/
JUPITER_API int findSymbol(const char *str, char c, int n);

/**
* @brief Checks if a character exists in a string.
*
* @param str String to scan.
* @return True if it contains a given character, false otherwise.
*/
JUPITER_API bool containsSymbol(const char *str, char c);

/**
* @brief Creates a copy of a string.
*
* @param str String to copy.
* @return String containing a copy of the input string on success, NULL otherwise.
*/
JUPITER_API char *makestr(const char *str);

/**
* @brief returns the current time in a string format.
* This will vary depending on locale.
* Format: Day_of_week Month Day hh:mm:ss Year Timezone.
* Example 1: Sun Aug 18 13:52:21 2013 EST
* Example 2: Thu Nov 14 03:52:57 2013 Eastern Standard Time
* Exmaple 3: Sun Nov 17 15:06:19 2013 Tokyo Standard Time
*
* @return A string containing the time in the format specified above.
*/
JUPITER_API char *getTime();

/**
* @brief Gets the next power of 2 after a specified number.
*
* @param number 32-bit integer to start from.
* @return Next highest power of 2.
*/
JUPITER_API uint32_t getPowerTwo32(uint32_t number);

/**
* @brief Gets the next power of 2 after a specified number.
*
* @param number 64-bit integer to start from.
* @return Next highest power of 2.
*/
JUPITER_API uint64_t getPowerTwo64(uint64_t number);

#if defined __cplusplus
}

/** strlen implementation */
template<typename T> inline size_t Jupiter::strlen(const T *str)
{
	register const T *s = str;
	while (*s != 0) s++;
	return s - str;
}

/** strcpy implementation */
template<typename T> inline T *Jupiter::strcpy(T *dest, const T *source)
{
	register T *d = dest;
	while (*source != 0)
	{
		*d = *source;
		d++;
		source++;
	}
	*d = *source;
	return dest;
}

/** strcpy implementation */
template<typename T> inline T *Jupiter::strcpy(T *dest, const T *source, size_t length)
{
	dest[length] = 0;
	while (length > 0)
	{
		length--;
		dest[length] = source[length];
	}
	return dest;
}

template<typename T> inline const T *Jupiter::strpbrk(const T *str1, const T *str2)
{
	const T *s;
	while (*str1 != 0)
	{
		s = str2;
		while (*s != 0)
		{
			if (*str1 == *s) return str1;
			s++;
		}
		str1++;
	}
	return nullptr;
}

template<typename T> inline const T *Jupiter::strpbrk(const T *str1, const T e)
{
	while (*str1 != 0)
	{
		if (*str1 == e) return str1;
		str1++;
	}
	return nullptr;
}

template<typename T> inline bool Jupiter::streql(const T *str1, const T *str2)
{
	if (str1 == str2) return true;
	while (*str1 != 0 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 == *str2);
}

#endif // __cplusplus

#endif // _FUNCTIONS_H_HEADER