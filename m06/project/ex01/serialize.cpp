#include "data.hpp"

/*
Simply reinterpret the pointer as an 8 byte int
*/

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t> (ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*> (raw);
}
