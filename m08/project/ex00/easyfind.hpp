#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/*
typename usage explanation:

	- https://en.cppreference.com/w/cpp/language/dependent_name
	( The typename disambiguator for dependent names )

	Return: container.end() if not found
	essentially just use the std::find ...
*/

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int n) {
	return std::find(container.begin(), container.end(), n);
}

#endif /* EASYFIND_HPP */
