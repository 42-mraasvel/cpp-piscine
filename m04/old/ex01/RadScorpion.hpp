#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy {

public:

	RadScorpion();
	RadScorpion(const RadScorpion& from);
	~RadScorpion();

	RadScorpion& operator=(const RadScorpion& rhs);

};

#endif /* RADSCORPION_HPP */
