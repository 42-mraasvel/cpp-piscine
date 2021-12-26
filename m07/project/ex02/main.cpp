#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
void ExampleTests() {
	std::cout << " ** EXAMPLE TESTS ** " << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
}

template <typename T>
void PrintArray(const Array<T>& array) {
	for (unsigned int i = 0; i < array.size(); i++) {
		if (i != 0) {
			std::cout << ' ';
		}
		std::cout << array[i];
	}
	std::cout << std::endl;
}

void TestBasicArray() {
	Array<int> array(10);
	Array<int> assign_array;
	Array<int> copy_array(array);

	assign_array = array;

	// Assign different values to each array
	// To show deep copies are made
	for (size_t i = 0; i < array.size(); i++) {
		array[i] = i + 1;
		assign_array[i] = (i + 1) * 10;
		copy_array[i] = (i + 1) * 100;
	}

	PrintArray(array);
	PrintArray(assign_array);
	PrintArray(copy_array);
}

int main(void) {
	ExampleTests();
	std::cout << std::endl;
	TestBasicArray();

	// Default constructor called: no elements
	Array<std::string> empty_array;

	try {
		// Trigger exception by overflowing
		empty_array[0] = "abcd";
	} catch (const std::exception& e) {
		std::cout << "Caught: " << e.what() << " after bad indexing" << std::endl;
	}

	// Assign new array with bigger size
	empty_array = Array<std::string>(10);

	// Now this works fine
	empty_array[0] = "HELLO!";
	return 0;
}
