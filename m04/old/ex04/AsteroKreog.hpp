#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP

# include <string>
# include "IAsteroid.hpp"

// Comet class

class AsteroKreog : public IAsteroid {

public:

	AsteroKreog();
	AsteroKreog(const AsteroKreog& from);
	~AsteroKreog();

	AsteroKreog& operator=(const AsteroKreog& rhs);

	virtual std::string beMined(DeepCoreMiner* laser) const;
	virtual std::string beMined(StripMiner* laser) const;
	virtual std::string getName() const;

};

#endif /* ASTEROKREOG_HPP */
