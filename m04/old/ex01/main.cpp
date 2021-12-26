#include <iostream>
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include "Lightsaber.hpp"
#include "Rancor.hpp"

void ExampleTests() {

	std::cout << " **** EXAMPLE TESTS ****" << std::endl;
	Character *me = new Character("Maarten");

	std::cout << *me;

	Enemy *b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	//! The example had leaks ...
	delete pf;
	delete pr;
	delete me;
}

void OwnTests() {

	std::cout << " **** OWN TESTS ****" << std::endl;

	Character *me = new Character("Some Guy");
	Lightsaber *ls = new Lightsaber();

	std::cout << *me;

	Enemy *supermutant = new SuperMutant();
	Enemy *rancor = new Rancor();
	me->attack(rancor); //! Attack doesn't happen because there's no weapon equipped

	// Equip weapon and print status
	me->equip(ls);
	std::cout << *me << std::endl;

	me->attack(rancor);
	me->attack(supermutant);

	std::cout << std::endl << "HP Rancor: " << rancor->getHP() << std::endl;
	std::cout << "HP SuperMutant: " << supermutant->getHP() << std::endl;

	std::cout << *me;
	me->attack(supermutant); //! Can't attack because not enough AP
	
	//! Recover 4 times : 10 -> 40, because 40 is the max
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();

	std::cout << *me << std::endl;
	// Kill rancor so it gets deleted
	me->attack(rancor);
	me->attack(rancor);
	me->recoverAP();
	me->attack(rancor);

	std::cout << std::endl << *me;
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	std::cout << std::endl << *me;

	// Kill supermutant so that it gets deleted
	me->attack(supermutant);
	me->attack(supermutant);

	delete me;
	delete ls;
}

int main(void) {

	ExampleTests();
	std::cout << std::endl;

	OwnTests();

	return 0;
}
