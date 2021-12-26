#include "Bureaucrat.hpp"
#include "Form.hpp"

/* Constructors */

Bureaucrat::Bureaucrat()
	: name(""), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
	: name(name), grade(grade) {
	
	if (grade < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& from)
	: name(from.getName()), grade(from.getGrade()) {}

Bureaucrat::~Bureaucrat() {}


/* Operators */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this == &rhs) {
		return *this;
	}
	grade = rhs.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return out;
}


/* Methods */

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	grade += 1;
}

void Bureaucrat::signForm(Form& form) const {

	// Return if the form is already signed?
	if (form.isSigned()) {
		return;
	}

	try {
		form.beSigned(*this);
		std::cout << getName() << " signs " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

/* Exception Definitions */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "GradeTooLowException";
}
