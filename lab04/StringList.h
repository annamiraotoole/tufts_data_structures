#ifndef __STRINGLIST_H__
#define __STRINGLIST_H__

#include <string>

class StringList
{
public:
        /*
         * Rather than a constructor, client's call this static member
         * function to get a new empty list.
         */
        static StringList *empty();

        /*
         * Essential member functions
         */
        bool       isEmpty();
        StringList *prepend(std::string s);
        std::string first();
        StringList *rest();

        /*
         * Convenient member functions:  These can all be written
         * using the functions above.
         */
        int         length();
        bool        equals(StringList *other);
        StringList *append(StringList *other);
        StringList *reverse();
        std::string oneWord();
        void        print();
        void        println();

        /*
         * YUK!
         * This is painful to look at, but it lets you initialize lists
         * easily for testing purposes, and, yes, it has to be in the .h file.
         *
         * Use it like this:
         *
         *      StringList *example = StringList::stringsToList("one", "two");
         *
         * to get a two-element list ["one", "two"].
         */
        template<typename... StringArgs>
        static StringList *stringsToList(StringArgs&&... ss)
        {
                return stringsToList({std::forward<StringArgs>(ss)...});
        }

        static StringList *arrayToList(std::string strings[], int length);

        ~StringList();

private:
        std::string str;
        StringList *next;

        static StringList *theEmptyStringList;

        StringList(std::string s, StringList *theRest = nullptr);
        StringList *reverse(StringList *result);
        static StringList *stringsToList(std::initializer_list<std::string>&& ss);
        void ensureNonEmpty(std::string functionName);

        /*
         * The following are not defined, and I don't want clients to
         * use them.  Making them private forces clients to use only
         * the functions explicitly defined above.
         */
        StringList();
        StringList(StringList &sl);
        StringList &operator=(const StringList &sl);
};

#endif
