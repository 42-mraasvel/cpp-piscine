#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {

public:

	Contact();

	bool IsEmpty() const;
	void GetContactInfo();
	void SetIndex(size_t index);
	void PrintInfo(void) const;
	void PrintColumn(void) const;


private:

	void _GetString(std::string& dst, const std::string& query);
	void _PrintStringFormat(std::string content, int w) const;
	void _PrintInfoDictFormat(std::string a, std::string b) const;

	int _total_fields;
	size_t _index;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

};

#endif /* CONTACT_HPP */
