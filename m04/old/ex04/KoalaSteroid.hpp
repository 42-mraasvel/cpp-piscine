#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

# include <string>
# include "IAsteroid.hpp"

// Asteroid class

class KoalaSteroid : public IAsteroid {

public:

	KoalaSteroid();
	KoalaSteroid(const KoalaSteroid& from);
	~KoalaSteroid();

	KoalaSteroid& operator=(const KoalaSteroid& rhs);

	virtual std::string beMined(DeepCoreMiner* laser) const;
	virtual std::string beMined(StripMiner* laser) const;
	virtual std::string getName() const;

};

#endif /* KOALASTEROID_HPP */
