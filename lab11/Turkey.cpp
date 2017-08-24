#include <iostream>
#include <functional>
#include "Turkey.h"

Turkey::Turkey()
{
	firstName = "";
	lastName = "";
	weight = -1;
	hashFunction = std::hash<std::string>{};
}

Turkey::Turkey(std::string first,std::string last,int inWeight)
{
	firstName = first;
	lastName = last;
	weight = inWeight;
	hashFunction = std::hash<std::string>{};
}

std::size_t Turkey::hash()
{
	std::string combined_name = firstName + lastName;
	return hashFunction(combined_name);

}

void Turkey::print()
{
	std::string descriptor = "lean";
	if(weight > 10)
	{
		descriptor = "plump";
	}
	if(weight > 15)
	{
		descriptor = "fat";
	}
	std::cout << firstName << " \"" << lastName << "\""
		  << " is a " << descriptor <<  " Turkey";
}

void Turkey::updateLastName(std::string newName)
{
	lastName = newName;
}
