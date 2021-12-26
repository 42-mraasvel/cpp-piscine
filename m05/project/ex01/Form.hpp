#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {

/* Constructors/Destructors */

private:
	Form();

public:
	Form(const std::string& name, const int& sign_grade, const int& exec_grade);
	Form(const Form&);
	~Form();

/* Operators */
	Form& operator=(const Form&);

/* Methods */
	const std::string& getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat&);

/* Exceptions */
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
/* Attributes */
	const std::string name;
	const int sign_grade;
	const int exec_grade;
	bool is_signed;

};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif /* FORM_HPP */
