#include <iostream>
#include <string>

int main(void) {

	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string& stringREF = str; // Must be initialized during declaration

	std::cout << "Address using [PTR]  stringPTR == " << stringPTR << std::endl;
	std::cout << "Address using [REF] &stringREF == " << &stringREF << std::endl;

	std::cout << "String using  [PTR] *stringPTR == " << *stringPTR << std::endl;
	std::cout << "String using  [REF]  stringREF == " << stringREF << std::endl;

	return 0;
}
