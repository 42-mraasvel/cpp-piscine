#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {

public:

	Zombie(void);
	Zombie(std::string name, std::string type);
	Zombie(const Zombie& from);
	~Zombie(void);

	void announce(void) const;
	void SetName(std::string name);
	void SetType(std::string type);

	static std::string RandomName(void);
	static std::string RandomType(void);

private:

	/* Static because they're not really related to the instance */
	static std::string RandomString(size_t len);
	static std::string RandomNamePool(void);
	static std::string RandomTypePool(void);

	std::string _name;
	std::string _type;

};

#endif /* ZOMBIE_HPP */
