#include <iostream>
#include "MiningBarge.hpp"
#include "AsteroKreog.hpp"
#include "KoalaSteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

int main(void) {

	IAsteroid* comet = new AsteroKreog();
	IAsteroid* asteroid = new KoalaSteroid();

	MiningBarge barge;

	IMiningLaser* strip = new StripMiner();
	IMiningLaser* deep = new DeepCoreMiner();

	barge.equip(strip);
	barge.equip(deep);
	std::cout << "Mining on comet:" << std::endl;
	barge.mine(comet);
	std::cout << std::endl << "Mining on asteroid:" << std::endl;
	barge.mine(asteroid);


	delete deep;
	delete strip;

	delete asteroid;
	delete comet;

	return 0;
}
