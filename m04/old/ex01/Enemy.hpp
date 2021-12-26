#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy {

protected:

	Enemy();

	int hitpoints;
	std::string type;

public:

	Enemy(int hp, std::string const& type);
	Enemy(const Enemy& from);
	Enemy& operator=(const Enemy& rhs);
	virtual ~Enemy();

	std::string const& getType() const;
	int getHP() const;

	virtual void takeDamage(int amount);

};

#endif /* ENEMY_HPP */
