#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#include "easyfind.hpp"

template <typename T>
void TestContainer(T& container, int n) {

	std::cout << "Search(" << n << "): ";
	typename T::iterator it = easyfind<T>(container, n);

	// Check the return value
	if (it == container.end()) {
		std::cout << "easyfind: returned iterator not found" << std::endl;
	} else {
		std::cout << "Found(" << *it << ')' << std::endl;
	}
}


/*
Print container
*/
void PrintItem(int x) {
	std::cout << ' ' << x;
}

template <typename Container>
void PrintContainer(const Container& container, const std::string& prefix) {
	typename Container::const_iterator start = container.begin();
	typename Container::const_iterator end = container.end();

	std::cout << prefix << ":";
	std::for_each(start, end, PrintItem);
	std::cout << std::endl;
}

void TestVector() {
	std::vector<int> v;

	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	PrintContainer(v, " ** VECTOR **");
	std::cout << std::endl;

	TestContainer(v, 3);
	TestContainer(v, 1);
	TestContainer(v, -1);
}

void TestList() {
	std::list<int> lst;

	lst.push_back(INT_MAX);
	lst.push_back(INT_MIN);
	lst.push_back(0);
	lst.push_back(-1);
	lst.push_back(1);

	PrintContainer(lst, " ** LIST **");
	std::cout << std::endl;

	TestContainer(lst, INT_MAX);
	TestContainer(lst, INT_MIN);
	TestContainer(lst, 42);
	TestContainer(lst, 0);
	TestContainer(lst, 420);

}

int main(void) {

	TestVector();
	std::cout << std::endl;
	TestList();
	return 0;
}
