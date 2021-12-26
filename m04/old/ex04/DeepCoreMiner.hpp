#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {

public:

	DeepCoreMiner();
	DeepCoreMiner(const DeepCoreMiner& from);
	~DeepCoreMiner();

	DeepCoreMiner& operator=(const DeepCoreMiner& rhs);

	virtual void mine(IAsteroid* asteroid);

};

#endif /* DEEPCOREMINER_HPP */
