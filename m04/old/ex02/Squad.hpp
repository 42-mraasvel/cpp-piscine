#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad {

public:

	Squad();
	Squad(const Squad& from);
	~Squad();

	Squad& operator=(const Squad& rhs);

	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int index) const;
	virtual int push(ISpaceMarine*);

private:

	void clear();
	void ensureCapacity();
	bool unitInSquad(ISpaceMarine*);

	int size;
	int nmemb;
	ISpaceMarine** table;

};

#endif /* SQUAD_HPP */
