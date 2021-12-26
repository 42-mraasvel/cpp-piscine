#include "IMiningLaser.hpp"
#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid() {}

KoalaSteroid::KoalaSteroid(const KoalaSteroid& from) {
	(void)from;
}

KoalaSteroid::~KoalaSteroid() {}

KoalaSteroid& KoalaSteroid::operator=(const KoalaSteroid& rhs) {
	(void)rhs;
	return *this;
}

/*
If laser == StripMiner : return "Flavium"
else if laser == DeepCoreMiner : return "Dragonite"
*/

std::string KoalaSteroid::beMined(StripMiner* laser) const {
	(void)laser;
	return "Flavium";
}

std::string KoalaSteroid::beMined(DeepCoreMiner* laser) const {
	(void)laser;
	return "Dragonite";
}


std::string KoalaSteroid::getName() const {
	return "KoalaSteroid";
}
