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

	Form(const std::string& name, int sign, int exec);
	Form(const std::string& name, const std::string& target, int sign, int exec);
	Form(const Form&);
	virtual ~Form();

/* Operators */

	Form& operator=(const Form&);

/* Methods */

	const std::string& getName() const;
	const std::string& getTarget() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat&);
	void execute(const Bureaucrat&) const;

/* Exceptions */

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class FormAlreadySignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:

/* Attributes */

	const std::string name;
	const std::string target;
	const int sign_grade;
	const int exec_grade;
	bool is_signed;

	virtual void action() const = 0;

};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif /* FORM_HPP */
