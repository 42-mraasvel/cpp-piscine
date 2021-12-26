#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat {

public:

/* Constructors */

	Bureaucrat();
	Bureaucrat(const std::string& name, const int grade);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();

/* Operators */

	Bureaucrat& operator=(const Bureaucrat&);

/* Methods */

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

/* Exceptions */

	// Note: exception classes do not need to be in orthodox canonical form.
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
	int grade;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif /* BUREAUCRAT_HPP */
