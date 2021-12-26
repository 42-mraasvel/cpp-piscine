#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>

class Victim;

class Sorcerer {

public:

	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer& from);
	~Sorcerer();
	Sorcerer& operator=(const Sorcerer& rhs);

	const std::string& GetName() const;
	const std::string& GetTitle() const;

	void polymorph(Victim const& victim) const;

private:

	Sorcerer();

	std::string name;
	std::string title;

};

std::ostream& operator<<(std::ostream& out, const Sorcerer& rhs);

#endif /* SORCERER_HPP */
