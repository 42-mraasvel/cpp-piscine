#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include "Brain.hpp"

class Human {

public:

	Human();
	~Human();

	const Brain& getBrain(); // Return a reference so that the address is the same
	std::string identify() const;

private:

	const Brain brain;

};

#endif /* HUMAN_HPP */
