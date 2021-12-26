// #include <iostream>
// #include "Character.hpp"
// #include "MateriaSource.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"

// void ExampleTests() {
// 	std::cout << " ** EXAMPLE TESTS ** " << std::endl;

// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;
// }

// void CharacterTests() {
// 	std::cout << " ** CHARACTER TESTS ** " << std::endl;

// 	// Creating a character
// 	ICharacter *me = new Character("Maarten");

// 	// Equipping new Materia and using it
// 	AMateria* tmp = new Ice();
// 	std::cout << "EQUIPING: " << tmp->getType() << std::endl;
// 	me->equip(tmp);
// 	std::cout << "USING: materia[0]" << std::endl;
// 	me->use(0, *me);

// 	// Adding the same, or NULL doesn't do anything
// 	me->equip(tmp);
// 	me->equip(NULL);

// 	// Filling rest of materia
// 	std::cout << "Equipping 3 Cures and using materia[3]:" << std::endl;
// 	me->equip(new Cure());
// 	me->equip(new Cure());
// 	me->equip(new Cure());
// 	me->use(3, *me);

// 	// Out of bounds indexing
// 	me->use(5, *me);
// 	me->use(-1, *me);

// 	// Unequip test
// 	me->unequip(0);
// 	delete tmp; // Unequipping won't delete tmp
// 	std::cout << "USING: materia[0] after unequipping:" << std::endl;
// 	me->use(0, *me); // Shouldn't do anything

// 	std::cout << "Equipping new materia, and using materia[0]:" << std::endl;
// 	me->equip(new Ice());
// 	me->use(0, *me);

// 	delete me;
// }

// void MateriaSourceTests() {
// 	std::cout << " ** MATERIA SOURCE TESTS ** " << std::endl;

// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());

// 	std::cout << "Trying to create unknown materia returns NULL:" << std::endl;
// 	AMateria* materia = src->createMateria("cure");
// 	std::cout << "AMateria* = " << materia << std::endl;

// 	std::cout << "Learning Cure() and creating it:" << std::endl;
// 	src->learnMateria(new Cure());
// 	materia = src->createMateria("cure");
// 	std::cout << "Got: " << materia->getType() << std::endl;
// 	delete materia;;

// 	delete src;
// }

// void CopyTest() {
// 	std::cout << " ** COPY TESTS ** " << std::endl;
// 	Character* original = new Character("Original");

// 	original->equip(new Cure());
// 	original->equip(new Ice());

// 	std::cout << "Creating a character copy" << std::endl;
// 	Character *copy = new Character(*original);
// 	std::cout << "Original's name: " << original->getName() << std::endl;
// 	std::cout << "Copy's name: " << copy->getName() << std::endl;

// 	// Also works with assignation: no double free because of deep copy
// 	Character assigner = *original;

// 	// Deleting copy is fine, because it was a deep copy
// 	delete copy;
// 	delete original;
// }

// int main(void) {
// 	ExampleTests();
// 	std::cout << std::endl;
// 	CharacterTests();
// 	std::cout << std::endl;
// 	MateriaSourceTests();
// 	std::cout << std::endl;
// 	CopyTest();
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 11:23:45 by salbregh      #+#    #+#                 */
/*   Updated: 2021/10/07 14:38:38 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int		main() {
	// IMateriaSource*	src = new MateriaSource;
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter*		me = new Character("me");

	// AMateria*		tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	// ICharacter*		bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;


	std::cout << std::endl << "EXTRA MAIN CHECKING DEEP COPY" << std::endl;
	IMateriaSource*		src2 = new MateriaSource;
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());

	ICharacter*		you = new Character("you");
	ICharacter*		you2 = new Character("you2");

	AMateria*		temp;
	temp = src2->createMateria("ice");
	// this materia will only be equiped with ice

	// try to use when not equiped yet.
	you->use(0, *you2);
	you->equip(temp);
	you->use(0, *you2);
	// you now holds a ice materia
	ICharacter	*copy(you);
	// check to see if copy now also holds an icebolt
	copy->use(0, *you2);
	you->use(0, *you2);
    copy->unequip(0);
	std::cout << "After unequipping" << std::endl;
	you->use(0, *you2);
	// copy->use(0, *you2);

	// temp = src2->createMateria("cure");
	// copy->equip(temp);
	// copy->use(0, *you2);
	// you->use(0, *you2);

	return (0);
}
