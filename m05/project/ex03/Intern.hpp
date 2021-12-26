#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>

class Form;

enum FormNames {
	SHRUBBERY = 0,
	ROBOTOMY = 1,
	PRESIDENTIAL = 2,
	UNKNOWN = 3
};

class Intern {

public:

	Intern();
	Intern(const Intern&);
	~Intern();

	Intern& operator=(const Intern&);

	Form* makeForm(const std::string& form_name, const std::string& form_target) const;

	class UnknownFormException : public std::exception {
	public:
		const char* what() const throw();
	};

};

#endif /* INTERN_HPP */
