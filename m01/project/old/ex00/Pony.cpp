#include <iostream>
#include "Pony.hpp"

/* Main Pony Functions */
void ponyOnTheHeap(void) {

	std::cout << "****Creating heap pony****" << std::endl << std::endl;
	Pony *pony = new Pony(180, 102, "Bill", "Shetlandpony"); // new allocates on the heap

	// Do some stuff

	std::cout << "Number of pony instances: " << Pony::GetInstanceCount() << std::endl << std::endl;
	pony->DisplayStatus();
	std::cout << std::endl;
	pony->DoStuff();
	std::cout << std::endl;

	std::cout << "**Deleting heap pony**" << std::endl;
	delete pony; // Delete memory
}

void ponyOnTheStack(void) {

	std::cout << "****Creating stack pony****" << std::endl << std::endl;
	Pony pony(158, 110, "Dream", "Appaloosa"); // Allocates memory on the stack

	// Do some stuff
	std::cout << "Number of pony instances: " << Pony::GetInstanceCount() << std::endl << std::endl;
	pony.DisplayStatus();
	std::cout << std::endl;
	pony.DoStuff();
	std::cout << std::endl;


	std::cout << "**Deleting stack pony**" << std::endl;
	// Stack gets deleted automatically at the end of a function
}


/* Constructor */
Pony::Pony() : _tired(false) {
	std::cout << "Pony Constructor" << std::endl;
	_instance_count += 1;
}


/* Constructor 2 with parameters, using initialization list */
Pony::Pony(int height, int weight, std::string name, std::string breed) : _height(height), _weight(weight), _name(name), _breed(breed), _tired(false) {
	std::cout << "Pony Constructor" << std::endl;
	_instance_count += 1;
}

/* Destructor */
Pony::~Pony() {
	std::cout << "Pony Destructor" << std::endl;
	_instance_count -= 1;
}


void Pony::DisplayStatus(void) {

	std::cout << "****Pony Status****" << std::endl;


	std::cout << "Height: " << _height << " cm" << std::endl;
	std::cout << "Weight: " << _weight << " kg" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Breed: " << _breed << std::endl;
	std::cout << "Tired: " << std::boolalpha << _tired << std::endl;

	std::cout << std::endl;
}

void Pony::DoStuff(void) {
	std::cout << "****Pony Does Stuff****" << std::endl;

	std::cout << _name << " is running around" << std::endl;
	std::cout << _name << " is drinking some water" << std::endl;
	std::cout << _name << " is tired and is done for the day" << std::endl;
	_tired = true;
}

/* Accessors */

int Pony::GetHeight(void) {
	return _height;
}

int Pony::GetWeight(void) {
	return _weight;
}

std::string Pony::GetName(void) {
	return _name;
}

std::string Pony::GetBreed(void) {
	return _breed;
}


/* To count number of pony instances to prove they're being deleted */

int Pony::GetInstanceCount(void) {
	return _instance_count;
}

int Pony::_instance_count = 0;
