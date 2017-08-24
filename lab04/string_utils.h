#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

/*
 * Return first character in given string as a 1-character string
 *
 * uses string "fill constructor" to fill a string with one copy of
 * the character
 */
std::string firstChar(std::string s);

/*
 * Return a string consisting of all the characters after the first.
 */
std::string restChars(std::string s);

#endif
