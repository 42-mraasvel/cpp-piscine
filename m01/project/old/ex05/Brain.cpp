#include <sstream>
#include "Brain.hpp"

Brain::Brain() {}

Brain::~Brain() {}

/*
https://www.cplusplus.com/reference/sstream/stringstream/
stringstream makes it easy to parse data from or to strings

std::hex converts int to hex string format
std::showbase adds 0x
*/

std::string Brain::identify() const {
	std::ostringstream oss;
	oss << std::hex << std::showbase << (size_t)this;
	return oss.str();
}
