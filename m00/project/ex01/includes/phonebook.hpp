#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook {

public:

	Phonebook();

	void Prompt();

private:

	void _AddEntry();
	void _SearchPhonebook();
	bool _ValidIndex(std::string index) const;

	const size_t _MAX_SIZE;
	size_t _size;
	size_t _index;
	Contact _contacts[8];

};

#endif /* PHONEBOOK_HPP */
