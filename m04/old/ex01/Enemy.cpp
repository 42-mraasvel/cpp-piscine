#include "Enemy.hpp"

Enemy::Enemy() {}

Enemy& Enemy::operator=(const Enemy& rhs) {

	if (this == &rhs) {
		return *this;
	}

	this->type = rhs.type;
	this->hitpoints = rhs.hitpoints;
	return *this;
}

Enemy::Enemy(int hp, std::string const& type)
	: hitpoints(hp), type(type) {}

Enemy::Enemy(const Enemy& from)
	: hitpoints(from.hitpoints), type(from.getType()){}

Enemy::~Enemy() {}

int Enemy::getHP() const {
	return hitpoints;
}

std::string const& Enemy::getType() const {
	return type;
}

void Enemy::takeDamage(int amount) {
	if (amount <= 0) {
		return;
	}

	hitpoints -= amount;

	if (hitpoints < 0) {
		hitpoints = 0;
	}
}
