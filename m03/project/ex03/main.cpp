#include <iostream>
#include "DiamondTrap.hpp"

int main(void) {

	DiamondTrap dt ( "DI4M0ND-TP" );

	std::cout << "HEALTH: " << dt.GetHitPoints() << std::endl;
	std::cout << "ENERGY: " << dt.GetEnergyPoints() << std::endl;
	std::cout << "ATTACK: " << dt.GetAttackDamage() << std::endl;

	dt.whoAmI();
	dt.attack("Target");
	dt.takeDamage(10);
	dt.beRepaired(10);

	dt.guardGate();
	dt.highFivesGuys();

	return 0;
}
