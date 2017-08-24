#include <string>

using std::string;

/*
 * Return first character in given string as a 1-character string
 *
 * uses string "fill constructor" to fill a string with one copy of
 * the character
 */
string firstChar(string s)
{
        return string(1, s[0]);
}

/*
 * Return a string consisting of all the characters after the first.
 */
string restChars(string s)
{
        string result = s;
        result.erase(0, 1);
        return result;
}
