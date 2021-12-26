#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"
#include "MiningBarge.hpp"

MiningBarge::MiningBarge()
	: size(0) {
	clearLasers();
}

MiningBarge::MiningBarge(const MiningBarge& from) {
	*this = from;
}

MiningBarge::~MiningBarge() {}

MiningBarge& MiningBarge::operator=(const MiningBarge& rhs) {
	if (this == &rhs) {
		return *this;
	}

	clearLasers();
	for (int i = 0; i < rhs.size; i++) {
		lasers[i] = rhs.lasers[i];
		size++;
	}

	return *this;
}

void MiningBarge::equip(IMiningLaser* laser) {
	if (size == 4 || laser == 0) {
		return;
	}
	lasers[size] = laser;
	size++;
}

void MiningBarge::mine(IAsteroid* asteroid) const {
	for (int i = 0; i < size; i++) {
		lasers[i]->mine(asteroid);
	}
}

void MiningBarge::clearLasers() {
	for (int i = 0; i < 4; i++) {
		lasers[i] = 0;
	}
	size = 0;
}
