#ifndef CAT_HPP
# define CAT_HPP

# include "Victim.hpp"

class Cat : public Victim {

public:

	Cat(const std::string& name);
	Cat(const Cat& from);
	~Cat();
	Cat& operator=(const Cat& rhs);

	virtual void getPolymorphed() const;

private:

	Cat();

};

std::ostream& operator<<(std::ostream& out, const Cat& rhs);

#endif /* CAT_HPP */
