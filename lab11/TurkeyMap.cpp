#include <iostream>
#include <functional>
#include "TurkeyMap.h"
#include "Turkey.h"

//Initialize the names of the families
std::string TurkeyMap::names[] =
{
	"Adams",
	"Butler",
	"Cook",
	"Davis",
	"Evans",
	"Fox",
	"Green",
	"Holmes",
	"Iles"//, The names were designed for a ten bucket map, not eleven
	//"Jones"
};

/* Initialize the buckets to null pointers
 * Initialize the offset map to -1
 * This makes it easy to know when an offset
 * has been used or not. If we initialized to
 * zero, we may not know whether the offset
 * is actually zero, or if it was just not
 * initialized
 *
 * takes: nothing
 * returns: nothing
 * throws: nothing
 */
TurkeyMap::TurkeyMap()
{
	for(int x = 0; x < 10; x++)
	{
		buckets[x] = NULL;
	}
	for(int x = 0; x < 9; x++)
	{
		offsets[x] = -1;
	}
}

/*
 * Print the TurkeyMap. All turkeys in
 * the zeroeth bucket are freed. All other
 * turkeys are eaten by thier respective
 * families.
 */
void TurkeyMap::print()
{
	// Print all saved turkeys
	Node *reader = buckets[0];
	if(reader == NULL)
	{
		std::cout << "No turkeys are pardoned!" << std::endl;
	}
	else
	{
		std::cout << "These turkeys are pardoned!" << std::endl;
	}
	while(reader != NULL)
	{
		std::cout << "\t";
		reader->turkey.print();
		std::cout << std::endl;
		reader = reader->next;
	}

	// Print all doomed turkeys, as well as the families
	for(int x = 0; x < 9; x++)
	{
		reader = buckets[x+1];
		std::cout << "The " << names[x] << " family eats";
		if(reader == NULL)
		{
			std::cout << " brussles sprouts" << std::endl;
		}
		else
		{
			std::cout << " these turkeys:" << std::endl;
		}
		while(reader != NULL)
		{
			std::cout << "\t";
			reader->turkey.print();
			std::cout << std::endl;
			reader = reader->next;
		}
	}
}
/*
 * This function takes a string and generates
 * the next string in a sequence. Basically, it
 * counts upwards in base 26.
 *
 * takes: a last name (string)
 * returns: the next last name in sequence (string)
 * throws: nothing
 */
std::string generateLastName(std::string input)
{
	// Copy the input string
	std::string transformed = input;

	// Base case
	if(transformed.length() == 0)
	{
		transformed += "a";
		return transformed;
	}
	

	// Carry case
	int carry = transformed.length()-1;
	while(transformed[carry] == 'z')
	{
		transformed[carry] = 'a';
		carry--;
		if(carry == -1)
		{
			// If we are at "zzz", return "aaaa"
			transformed = "a"+transformed;
			return transformed;
		}
	}

	// Increment the digits place
	transformed[carry] += 1;
	return transformed;
}


/*
 * addToBucket adds the given turkey to the bucket at the given index. 
 * 
 * takes: turkey,index
 * returns: nothing
 * sideEffect: adds turkey to map, resolving collisions with chaining
 */
void TurkeyMap::addToBucket(Turkey turkey,int bucketIndex)
{
	// If you want, implement this helper function.
	// You do not have to, but it will make your life much easier.
	// Remember to solve conflicts with chaining!

       if (buckets[bucketIndex].isEmpty())
           buckets[bucketIndex] = turkey;
       else if (buckets[offsets[bucketIndex] + bucketIndex].isEmpty()){
           addToBucket(turkey, offsets[bucketIndex] + bucketIndex);
       } else {
           // start chaining???
       }

}

// You must write this contract
void TurkeyMap::addTurkey(Turkey turkey)
{
	// Implement this function first!
	// It should add the given turkey to the TurkeyMap
	// in a fair manner. Resolve conflicts with chaining.
	// If this is called without the turkeys messing with thier names,
	// it should put no more than three turkeys in the same bucket.

        int hashResult = turkey.hash();
        addToBucket(turkey, hashResult);

}

//You must write this contract
void TurkeyMap::addTurkeySecure(Turkey turkey)
{
	// Implement this function third, or second if you are stuck.
	// Add the turkeys to the map in such a way that conflicts
	// are resolved using dynamic perfect hashing.
	//
	// The steps to dynamic perfect hashing are:
	// 1: find bucket index and offset index
	// 2: find offset, either by reading the offset index or doing
	// 	a linear probe
	// 3: add the turkey to the bucket with index bucketIndex + offset
	//
	// Remember, offsets by default are -1! If the offset if -1, you
	// need to find and set the offset before continuing.
	//
	// This is a difficult function to write. Work together! go one 
	// step at a time.
	std::cout << "addTurkeySecure NotImplemented" << std::endl;
}

// You must write this contract
void setLastName(Turkey &turkey)
{
	// Implement this function second.
	// Set the last name of the given turkey such that it will get placed
	// into bucket zero by addTurkey()
	//
	// We have provided you the function generateLastName(). Use it!
	std::cout << "setLstName NotImplemented" << std::endl;
}

// You must write this contract
void setLastNameSecure(Turkey &turkey)
{
	// Implement this function last.
	// Set the last name of the given turkey such that it will get placed
	// into bucket zero by addTurkeySecure()
	//
	// This code is very similar to setLastName, but it is much more
	// complicated to think about. Work with others!
	std::cout << "setLastNameSecure NotImplemented" << std::endl;

}
