#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void NormalAnimalTest() {
	std::cout << " ** NORMAL ANIMAL ** " << std::endl;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Dog's Type: " << dog->getType() << std::endl;
	std::cout << "Cat's Type: " << cat->getType() << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	delete cat;
	delete dog;
	delete meta;
}

void WrongAnimalTest() {
	std::cout << " ** WRONG ANIMAL ** " << std::endl;

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();

	std::cout << "WrongCat's Type: " << cat->getType() << std::endl;

	cat->makeSound();
	meta->makeSound();

	delete cat;
	delete meta;
}

int main(void) {
	NormalAnimalTest();
	std::cout << std::endl;
	WrongAnimalTest();
	return 0;
}
