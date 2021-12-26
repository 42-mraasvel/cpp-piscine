#include <iostream>
#include "StripMiner.hpp"
#include "IAsteroid.hpp"

StripMiner::StripMiner() {}

StripMiner::StripMiner(const StripMiner& from) {
	(void)from;
}

StripMiner::~StripMiner() {}


StripMiner& StripMiner::operator=(const StripMiner& rhs) {
	(void)rhs;
	return *this;
}

void StripMiner::mine(IAsteroid* asteroid) {
	std::cout << "* strip mining... got " << asteroid->beMined(this) << "! *" << std::endl;
}
