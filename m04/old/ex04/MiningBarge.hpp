#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

class IMiningLaser;
class IAsteroid;

class MiningBarge {

public:

	MiningBarge();
	MiningBarge(const MiningBarge& from);
	~MiningBarge();

	MiningBarge& operator=(const MiningBarge& rhs);

	void equip(IMiningLaser*);
	void mine(IAsteroid*) const;

private:

	void clearLasers();
	void deleteLasers();

	IMiningLaser* lasers[4];
	int size;

};

#endif /* MININGBARGE_HPP */
