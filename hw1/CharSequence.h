// CharSequence.h

// Annamira O'Toole 9/13/16

#ifndef CHARSEQUENCE_H
#define CHARSEQUENCE_H

class CharSequence
{
 private:

  static const int INIT_CAPACITY = 5;
  char    *charArray;
  int     count;
  int     capacity;

 public:

  CharSequence();
  CharSequence(char c);
  ~CharSequence();

  bool isEmpty();
  void clear();
  int size();
  void concatenate(CharSequence *p);
  char first();
  char last();
  char elementAt(int index);
  void print();
  void insertAtBack(char c);
  void insertAtFront(char c);
  void insertAt(char c, int index);
  void removeFromFront();
  void removeFromBack();
  void removeFrom(int index);
  void replace(char c, int index);


};

#endif
