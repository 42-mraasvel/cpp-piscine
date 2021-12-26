#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

public:

	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator& from);
	~AssaultTerminator();

	AssaultTerminator& operator=(const AssaultTerminator& rhs);

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

private:

};

#endif /* ASSAULTTERMINATOR_HPP */
