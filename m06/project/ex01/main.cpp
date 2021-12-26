#include <iostream>
#include "data.hpp"

static void PrintData(Data* ptr) {
	std::cout << "[DATA]: str1(" \
		<< ptr->str1 << "), str2(" \
		<< ptr->str2 << "), n(" \
		<< ptr->n << ")" << std::endl;
}

int main(void) {

	Data *ptr = new Data;

	ptr->n = 42;
	ptr->str1 = "Hello";
	ptr->str2 = "World";


	std::cout << "[" << ptr << "] ORIGINAL" << std::endl;
	PrintData(ptr);

	uintptr_t raw = serialize(ptr);
	std::cout << "[" << raw << "] RAW BYTES" << std::endl;

	Data* ptr2 = deserialize(raw);
	std::cout << "[" << ptr2 << "] DESERIALIZED" << std::endl;
	PrintData(ptr2);


	delete ptr;
	return 0;
}
