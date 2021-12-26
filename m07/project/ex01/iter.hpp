#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

int *lmao(void) {
	static int n = 0;

	return &n;
}

// template <typename T>
// void print(T const & x) {
// 	std::cout << x;
// }

/*
Function f() is able to modify values of the array, because they are passed by reference
*/
// template <typename T>
// void iter(const T* a, size_t len, void (*f)(const T&)) {

// 	if (a == NULL) {
// 		return;
// 	}

// 	for (size_t i = 0; i < len; i++) {
// 		f(a[i]);
// 	}
// }

template <typename T>
void iter(T* a, size_t len, void (*f)(T&)) {

	if (a == NULL) {
		return;
	}

	for (size_t i = 0; i < len; i++) {
		f(a[i]);
	}
}

#endif /* ITER_HPP */
