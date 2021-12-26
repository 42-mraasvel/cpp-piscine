#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include <string>

class Peon : public Victim {

public:

	Peon(const std::string& name);
	Peon(const Peon& from);
	~Peon();
	Peon& operator=(const Peon& rhs);

	virtual void getPolymorphed() const;

private:

	Peon();

};

#endif /* PEON_HPP */
