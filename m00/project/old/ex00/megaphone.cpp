/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/11 10:46:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/06/16 10:07:10 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Returns uppercase version of c
static char	ConvertUppercase(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 32;
	}
	return c;
}

// Norme is not mandatory for C++!
static void ParseArgs(int argc, char *argv[]) {

	// For loops are allowed in C++!
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			std::cout << ConvertUppercase(argv[i][j]);
		}
	}
	std::cout << std::endl;

}

int main(int argc, char *argv[]) {

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		ParseArgs(argc, argv);
	}

	return 0;
}
