/*
 *  A very simple, immutable string list implementation for doing some
 *  recursion exercises.
 *
 *  To make the exercises and this code easy, we are throwing memory
 *  management out the window.  Nothing is deleted.  Lists share
 *  structure, so deleting things would be a nightmare.
 *
 *  If I were deleting things, then I'd have to copy more stuff.  For
 *  this lab, it's unclear to me that that would be an improvement,
 *  though I've made no attempt to think it through :-)  But this is
 *  why people prefer garbage collected languages.
 *
 *  I think I prefer a non-OO approach for recursive list problems,
 *  but this is more what students are used to.
 *
 *  Author:  Mark A. Sheldon, Tufts University, Fall 2016
 *  
 */
#include <iostream>
#include <string>
#include <initializer_list>
#include <iterator>

#include "StringList.h"

using namespace std;

static void testStringList()   __attribute__ ((unused));

/*
 * Using the null pointer to represent empty lists.
 * But I'm giving it a nice name to distinguish this use from other
 * pointers, should any come up.
 */
StringList *StringList::theEmptyStringList = nullptr;

/*
 * A constructor that initializes a list node with the given string as
 * the first element and list of elements that should be the rest of
 * the list.
 *
 * Clients are not expected to use this.  This way, I can guarantee
 * it's always used with new and that all list instances are on the
 * heap. 
 */
StringList::StringList(string s, StringList *theRest)
        : str(s), next(theRest)
{
        // member initialization list did everything
}
        

/*
 * Return the empty list.
 */
StringList *StringList::empty()
{
        return theEmptyStringList;
}

/*
 * Return true if this list is empty, false otherwise.
 */
bool StringList::isEmpty()
{
        return this == theEmptyStringList;
}

/*
 * Return a new list that has the given string in front of all the
 * element in this list.
 */
StringList *StringList::prepend(string s)
{
        return new StringList{s, this};
}

/*
 * Return the first string in the list.
 */
string StringList::first()
{
        ensureNonEmpty("first");
        return str;
}

/*
 * Return the list of elements following the first element.
 */
StringList *StringList::rest()
{
        ensureNonEmpty("rest");
        return this->next;
}

/*
 * Return true if the two lists contain the same elemenents
 * and false otherwise.
 */
bool StringList::equals(StringList *other)
{
        if (this->isEmpty() and other->isEmpty())       /* Both are empty    */
                return true;
        else if (this->isEmpty() or other->isEmpty())   /* Only one is empty */
                return false;
        else
                return (this->first() == other->first())
                        and
                        this->rest()->equals(other->rest());
}

/*
 * Return a list consisting of the elements of this list followed by
 * the elements of the other list.
 *
 * Note:  Currently does not copy the other list, so lists will share
 * nodes.  If you want to use this in an environment where you
 * actually delete things, as you should, this will need to be
 * rewritten to copy the other list elements, too.
 */
StringList *StringList::append(StringList *other)
{
        if (isEmpty())
                return other;
        else
                return new StringList(this->first(),
                                      this->rest()->append(other));
}

/*
 * Print the list elements between square brackets separated by
 * commas:
 *   Empty list:            []   
 *   A three element list:  ["foo", "bar", "baz"]
 */
void StringList::print()
{
        StringList *current = this;

        cout << '[';
        while (not current->isEmpty()) {
                cout << "\"" << current->first() << "\"";
                if (not current->rest()->isEmpty())
                        cout << ", ";
                current = current->rest();
        }
        cout << ']';
}

/*
 * Print the list and then print a new line.
 */
void StringList::println()
{
        this->print();
        cout << endl;
}

/*
 * Return the length of (number of strings in) the list.
 */
int StringList::length()
{
        if (this->isEmpty())
                return 0;
        else
                return 1 + rest()->length();
}

/*
 * Return the result of concatenating all the strings in the list
 * together, left to right.
 *
 * Note:  Behold the ternary operator!  It's an "if expression" rather
 * than "if statement."
 */
string StringList::oneWord()
{
        return this->isEmpty() ? "" : first() + rest()->oneWord();
}
                
/*
 * Return a string list with the same strings as the array, in left to
 * write order:  i. e., strings[0] will be the first element.
 *
 * Very useful for debugging and writing test functions!
 */
StringList *StringList::arrayToList(string strings[], int length)
{
        StringList *result = empty();

        for (int i = length - 1; i >= 0; --i)
                result = result->prepend(strings[i]);

        return result;
}

/*
 * Return a list with the elements of the given list in reverse order.
 * Uses a helper function that takes the result accumulated so far.
 */
StringList *StringList::reverse()
{
        return reverse(empty());
}

/*
 * Reverse the elements of this list, accumulating the 
 * elements in result.
 */
StringList *StringList::reverse(StringList *result)
{
        if (this->isEmpty())
                return result;
        else
                return this->rest()->reverse(result->prepend(this->first()));
}

/*
 * Make sure the sequence is not empty.  Throw an exception if it is. 
 */
void StringList::ensureNonEmpty(string functionName)
{
        if (isEmpty())
                throw out_of_range(functionName
                                   + "Attempt to access element"
                                   + " in empty sequence");
}

StringList *StringList::stringsToList(std::initializer_list<string>&& ss)
{
        StringList *result = StringList::empty();

        /* 
         * Reverse iterators don't exist in C++11
         * And iterating in reverse order encountered 
         * memory corruption.
         */
        for (auto it = ss.begin(); it != ss.end(); ++it)
                result = result->prepend(*it);
        return result->reverse();
}

//
// Template moved to .h file
//
// template<typename... StringArgs>
// StringList *StringList::stringsToList(StringArgs&&... ss)
// {
//         return stringsToList({std::forward<StringArgs>(ss)...});
// }

/*
 * A woefully inadequate test.  If you haven't implemented at least
 * 100 linked lists, do more testing!  If you have, you should still
 * do more...
 */
static void testStringList()
{
        StringList *sl = StringList::empty();
        cout << "Empty list:  ";
        sl->println();
        cout << "Length:  " << sl->length() << endl;

        cout << endl;
        sl = sl->prepend("fun")->prepend("==")->prepend("C++");
        cout << "Three element list:  ";
        sl->println();
        cout << "Length:  " << sl->length() << endl;
        
        cout << endl;
        cout << "Concatenated together:  " << sl->oneWord() << endl;

        cout << endl;
        cout << "Testing variadic list maker..." << endl;
        cout << "Empty case:  ";
        StringList::stringsToList()->println();
        cout << "Singleton case:  ";
        StringList::stringsToList("alpha")->println();
        cout << "Five element case:  ";
        StringList::stringsToList("alpha", "bravo", "charlie",
                                  "delta", "echo")->println();
}

// int main(int argc, char *argv[])
// {
//         (void) argc;
//         (void) argv;

//         testStringList();

//         return 0;
// }
