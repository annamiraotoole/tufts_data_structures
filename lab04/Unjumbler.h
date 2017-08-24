/*
 *  Author:  Mitchell Katz, Tufts University, Fall 2016
 *
 *  The dictionary should really be a different class.  But it's
 *  included here as a quick and dirty solution.
 */
#ifndef __UNJUMBLER_H__
#define __UNJUMBLER_H__

#include <string>
#include <vector>

#include "StringList.h"


class Unjumbler
{
public:
        Unjumbler();
        Unjumbler(std::string wordsfile);

        StringList *unjumble(std::string s);
        void        test();

private:
        StringList *remove(std::string s, StringList *words);
        bool test_remove();

        StringList *removeDuplicates(StringList *words);
        bool test_removeDuplicates();

        StringList *mapConcat(std::string s, StringList *words);
        bool test_mapConcat();

        StringList *insertions(std::string s1, std::string s2);
        bool test_insertions();

        StringList *insertionsList(std::string s, StringList *words);
        StringList *permutations(std::string s);
        StringList *filterWords(StringList *words);

        bool        test_unjumble();

        void initWordsFromFile(std::string filename);
        bool isWord(std::string s);
        std::vector<std::string> words;
};

#endif
