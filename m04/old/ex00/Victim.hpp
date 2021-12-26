#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>

class Victim {

public:

	Victim(const std::string& name);
	Victim(const Victim& from);
	~Victim();

	Victim& operator=(const Victim& rhs);

	const std::string& GetName() const;
	virtual void getPolymorphed() const;

protected:

	Victim();

	std::string name;

};

std::ostream& operator<<(std::ostream& out, const Victim& rhs);

#endif /* VICTIM_HPP */
