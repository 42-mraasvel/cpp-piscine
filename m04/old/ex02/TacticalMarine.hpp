#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

public:

	TacticalMarine();
	TacticalMarine(const TacticalMarine& from);
	~TacticalMarine();

	TacticalMarine& operator=(const TacticalMarine& rhs);

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

private:

};

#endif /* TACTICALMARINE_HPP */
