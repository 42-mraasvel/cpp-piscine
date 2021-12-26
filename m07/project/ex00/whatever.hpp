#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
	T tmp(a);
	a = b;
	b = tmp;
}

template <typename T>
T min(const T& a, const T& b) {
	// Ternary: if a < b; return A else return B
	return a < b ? a : b;
}

template <typename T>
T max(const T& a, const T& b) {
	// Ternary: if a > b; return A else return B
	return a > b ? a : b;
}

#endif /* WHATEVER_HPP */
