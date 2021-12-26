#include <iostream>
#include "mutantstack.hpp"

void ExampleTests() {
	std::cout << " ** EXAMPLE TESTS ** " << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "TOP: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "SIZE: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Copy constructor test
	std::stack<int> s(mstack);
}

template <typename T>
void PrintStack(MutantStack<T> ms) {
	typename MutantStack<T>::iterator it = ms.begin();
	typename MutantStack<T>::iterator ite = ms.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

void MoreTests() {
	std::cout << " ** MORE TESTS ** " << std::endl;

	MutantStack<std::string> ms;

	ms.push("hello");
	ms.push("1234");
	ms.push("this is a string");
	ms.push("test");
	PrintStack(ms);


	MutantStack<std::string>::iterator it = ms.begin();
	MutantStack<std::string>::iterator ite = ms.end();

	std::cout << " ** MODIFYING STACK **" << std::endl;
	while (it != ite) {
		*it = "MODIFIED";
		it++;
	}
	PrintStack(ms);
}

void AssignmentTests() {
	std::cout << " ** ASSIGNMENT TESTS **" << std::endl;
	MutantStack<int> ms;

	std::cout << " ORIGINAL:" << std::endl;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);

	PrintStack(ms);

	std::cout << " ASSIGNMENT:" << std::endl;
	MutantStack<int> assign = ms;
	PrintStack(assign);

	std::cout << " COPY:" << std::endl;
	MutantStack<int> copy(ms);
	PrintStack(copy);
}

void DecrementTest() {
	std::cout << " ** DECREMENTING TEST **" << std::endl;

	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);

	std::cout << " STACK" << std::endl;
	PrintStack(ms);

	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator ite = ms.end();

	ite--;
	--it;

	std::cout << " START AT END:" << std::endl;
	while (ite != it) {
		std::cout << *ite << std::endl;
		--ite;
	}
}

void ConstTest() {
	MutantStack<int> ms;
	for (int i = 0; i < 5; ++i) {
		ms.push(i);
	}

	MutantStack<int>::const_reverse_iterator rit = ms.crbegin();
	MutantStack<int>::const_reverse_iterator rite = ms.crend();

	while (rit != rite) {
		// *rit = -1;
		std::cout << *rit << std::endl;
		++rit;
	}
}

int main(void) {
	ExampleTests();
	std::cout << std::endl;
	MoreTests();
	std::cout << std::endl;
	AssignmentTests();
	std::cout << std::endl;
	DecrementTest();
	std::cout << std::endl;
	ConstTest();
	return 0;
}
