#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {

public:

	Zombie(void);
	Zombie(std::string name, std::string type);
	~Zombie(void);

	void announce(void) const;
	void SetName(std::string name);
	void SetType(std::string type);

	/* Static because they're not really related to the instance */
	static std::string RandomNamePool(void);
	static std::string RandomName(size_t len);
	static std::string RandomTypePool(void);

private:

	std::string _name;
	std::string _type;

};

#endif /* ZOMBIE_HPP */
