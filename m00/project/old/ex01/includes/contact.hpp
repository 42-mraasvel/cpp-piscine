#ifndef CONTACT_HPP
# define CONTACT_HPP

/*

Contact Fields:

	first name
	last name
	nickname
	login
	postal address
	email address
	phone number
	birthday date
	favorite meal
	underwear color
	darkest secret


*/

class Contact {

public:

	Contact(void);
	Contact(int index);
	~Contact(void);

	void PrintColumn(void) const;
	void PrintInfo(void) const;
	int GetTotal(void) const;


private:

	std::string _GetInfoString(std::string name);
	void _PrintStringFormat(std::string content, int w) const;
	void _PrintInfoDictFormat(std::string a, std::string b) const;

	int _index;
	int _total;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _login;
	std::string _postal_address;
	std::string _email_address;
	std::string _phone_number;
	std::string _birthday_date;
	std::string _favorite_meal;
	std::string _underwear_color;
	std::string _darkest_secret;

};

#endif /* CONTACT_HPP */
