#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "contact.hpp"

std::string GetString(std::string query);

class Phonebook {

public:

	Phonebook(void);
	~Phonebook(void);

	void Prompt(void);

private:

	void Search() const;
	void Add();
	bool ValidIndex(std::string index) const;


	int const max_size;
	int size;
	Contact contacts[8];

};

#endif /* PHONEBOOK_HPP */
