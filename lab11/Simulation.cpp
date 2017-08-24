#include <vector>
#include <iostream>
#include "TurkeyMap.h"

/*
 * This function creates an initial vector of Turkeys
 *
 * takes: nothing
 * returns: a vector of turkeys
 *
 */
std::vector<Turkey> *initializeTurkeys()
{
	std::vector<Turkey> *turkeyList= new std::vector<Turkey>;
	turkeyList->push_back(Turkey("Alphred","",10));
	turkeyList->push_back(Turkey("Beatrice","",15));
	turkeyList->push_back(Turkey("Charlie","",17));
	turkeyList->push_back(Turkey("Deandre","",22));
	turkeyList->push_back(Turkey("Edna","",13));
	turkeyList->push_back(Turkey("Fred","",12));
	turkeyList->push_back(Turkey("Gabby","",7));
	turkeyList->push_back(Turkey("Henry","",9));
	turkeyList->push_back(Turkey("Iarlaith","",17));
	turkeyList->push_back(Turkey("Jadzia","",13));
	return turkeyList;
}

/*
 * This function executes the simulation of different
 * scenarios. It simulates first a run of addTurkey,
 * then a run of setLastName followed by addTurkey,
 * then a run of setLatName followed by addTurkeySecure,
 * then a run of setLastNameSecure followed by addTurkeySecure
 *
 * takes: nothing
 * returns:nothing:
 * prints: the simulation runs
 */
void Simulate()
{
	// The datastructures being tested
	std::vector<Turkey> *turkeys = initializeTurkeys();
	TurkeyMap map;	

	// First Run
	map = TurkeyMap();
	std::cout << std::endl << "First Test:" << std::endl;
	for(std::size_t c = 0; c < turkeys->size(); c++)
	{
		map.addTurkey((*turkeys)[c]);
	}
	map.print();

	// Second Run	
	map = TurkeyMap();
	std::cout << std::endl << "Second Test:" << std::endl;
	for(std::size_t c = 0; c < turkeys->size(); c++)
	{
		setLastName((*turkeys)[c]);
		map.addTurkey((*turkeys)[c]);
	}
	map.print();

	// Third Run	
	map = TurkeyMap();
	std::cout << std::endl << "Third Test:" << std::endl;
	for(std::size_t c = 0; c < turkeys->size(); c++)
	{
		setLastName((*turkeys)[c]);
		map.addTurkeySecure((*turkeys)[c]);
	}
	map.print();

	// Fourth Run
	map = TurkeyMap();
	std::cout << std::endl << "Fourth Test:" << std::endl;
	for(std::size_t c = 0; c < turkeys->size(); c++)
	{
		setLastNameSecure((*turkeys)[c]);
		map.addTurkeySecure((*turkeys)[c]);
	}
	map.print();
	delete turkeys;
}



/*
 * The entrypoint of the simulation
 * 
 * takes: nothing
 * returns: nothing
 */
int main()
{
	Simulate();	
}
