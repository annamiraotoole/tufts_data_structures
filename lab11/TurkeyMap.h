#include <functional>
#include "Turkey.h"

/*
 * The TurkeyMap class stores a hashmap of turkeys.
 * Each turkey is stored in a bucket. The buckets are
 * pointers to the heads of linked lists, this makes
 * implementing chaining easy.
 *
 * The TurkeyMap class also stores an array of offsets.
 * This array can be used to implement secondary hashing.
 */
class TurkeyMap
{
public:
	TurkeyMap();
	void addTurkey(Turkey);
	void addTurkeySecure(Turkey);
	void print();
private:
	void addToBucket(Turkey,int);
	struct Node
	{
		Node *next;
		Turkey turkey;
	};
	Node *buckets[10];
	int offsets[9];
	static std::string names[9];
};

void setLastName(Turkey&);
void setLastNameSecure(Turkey&);
