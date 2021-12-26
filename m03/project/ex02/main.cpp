#include <iostream>
#include "FragTrap.hpp"

int main(void) {

	FragTrap frag( "FragMaarten" );

	frag.attack("Target");
	frag.beRepaired(10);
	frag.takeDamage(10);
	frag.highFivesGuys();
	return 0;
}
