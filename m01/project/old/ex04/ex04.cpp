#include <iostream>
#include <string>

int main(void) {

	std::string brain = "HI THIS IS BRAIN";

	std::string *brain_ptr = &brain; // Pointer
	std::string &brain_ref = brain; // Reference

	std::cout << " Original : " << brain << std::endl;

	// Pointers have to be dereferenced
	std::cout << "  Pointer : " << *brain_ptr << std::endl;
	// References do not have to be dereferenced, they are like an alias for variables
	std::cout << "Reference : " << brain_ref << std::endl;
	return 0;
}
