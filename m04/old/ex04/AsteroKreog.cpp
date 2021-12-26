#include "IMiningLaser.hpp"
#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"
#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog() {}

AsteroKreog::AsteroKreog(const AsteroKreog& from) {
	(void)from;
}

AsteroKreog::~AsteroKreog() {}


AsteroKreog& AsteroKreog::operator=(const AsteroKreog& rhs) {
	(void)rhs;
	return *this;
}

/*
If laser == StripMiner : return "Tartarite"
else if laser == DeepCoreMiner : return "Meium"
*/

std::string AsteroKreog::beMined(StripMiner* laser) const {
	(void)laser;
	return "Tartarite";
}

std::string AsteroKreog::beMined(DeepCoreMiner* laser) const {
	(void)laser;
	return "Meium";
}

std::string AsteroKreog::getName() const {
	return "AsteroKreog";
}
