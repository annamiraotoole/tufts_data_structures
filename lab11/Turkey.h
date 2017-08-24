#ifndef TURKEY_H
#define TURKEY_H
#include <functional>

/*
 * The turkey class stores a turkey.
 * Turkeys have a first name, a last name
 * and a weight. Turkeys can change thier
 * last names, but not thier first names.
 * 
 * The turkey class has a hash function that
 * creates a hash from the combined first and
 * last names of the turkey.
 */
class Turkey
{
public:
	Turkey();
	Turkey(std::string,std::string,int);
	void print();

	// This is NOT the function you are writing
	void updateLastName(std::string);

	// This is the public function that creates hashes of Turkeys
	std::size_t hash();
private:
	std::string firstName;
	std::string lastName;
	int weight;

	// This is the internal function that creates hashes of strings
	std::hash<std::string> hashFunction;
};
#endif
