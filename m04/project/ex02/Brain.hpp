#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {

public:

/* Constructors/Destructors */

	Brain();
	Brain(const Brain&);
	~Brain();

/* Operators */

	Brain& operator=(const Brain&);

private:

/* Attributes */

	std::string ideas[100];

};

#endif /* BRAIN_HPP */
