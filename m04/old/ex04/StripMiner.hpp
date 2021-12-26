#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {

public:

	StripMiner();
	StripMiner(const StripMiner& from);
	~StripMiner();

	StripMiner& operator=(const StripMiner& rhs);

	virtual void mine(IAsteroid* asteroid);

};

#endif /* STRIPMINER_HPP */
