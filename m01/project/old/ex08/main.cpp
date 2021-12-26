#include "Human.hpp"

int main(void) {
	Human human;

	human.action("meleeAttack", "some random person");
	human.action("rangedAttack", "some random person");
	human.action("intimidatingShout", "some random person");
	human.action("notAnAction", "some random person");
	return 0;
}
