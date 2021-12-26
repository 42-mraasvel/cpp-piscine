#include <iostream>
#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"

DeepCoreMiner::DeepCoreMiner() {}

DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner& from) {
	(void)from;
}

DeepCoreMiner::~DeepCoreMiner() {}


DeepCoreMiner& DeepCoreMiner::operator=(const DeepCoreMiner& rhs) {
	(void)rhs;
	return *this;
}

void DeepCoreMiner::mine(IAsteroid* asteroid) {
	std::cout << "* mining deep... got " << asteroid->beMined(this) << "! *" << std::endl;
}
