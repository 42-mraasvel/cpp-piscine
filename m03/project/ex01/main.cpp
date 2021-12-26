#include <iostream>
#include "ScavTrap.hpp"

int main(void) {

	ScavTrap scav( "ScavMaarten" );

	scav.attack("Target");
	scav.beRepaired(10);
	scav.takeDamage(10);
	scav.guardGate();

	return 0;
}
