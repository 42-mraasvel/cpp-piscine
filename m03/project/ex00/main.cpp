#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap ct( "Maarten" );

	ct.attack("Target");
	ct.takeDamage(15);
	ct.beRepaired(10);
	return 0;
}
