#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: name(),
	sign_grade(MIN_GRADE),
	exec_grade(MIN_GRADE),
	is_signed(false) {}

Form::Form(const std::string& name, const int& sign_grade, const int& exec_grade)
	: name(name), sign_grade(sign_grade),
	exec_grade(exec_grade), is_signed(false) {

	if (exec_grade > MIN_GRADE || sign_grade > MIN_GRADE) {
		throw Form::GradeTooLowException();
	} else if (exec_grade < MAX_GRADE || sign_grade < MAX_GRADE) {
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form& from)
	: name(from.getName()),
	sign_grade(from.getSignGrade()), 
	exec_grade(from.getExecGrade()),
	is_signed(from.isSigned()) {}

Form::~Form() {}


/* Operators */

Form& Form::operator=(const Form& rhs) {
	(void)rhs;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& rhs) {
	out << rhs.getName() \
		<< ", form with SignGrade(" << rhs.getSignGrade() \
		<< "), and ExecGrade(" << rhs.getExecGrade() \
		<< "), Signed: " << std::boolalpha << rhs.isSigned() << std::endl;
	return out;
}

/* Methods */

const std::string& Form::getName() const {
	return name;
}

int Form::getSignGrade() const {
	return sign_grade;
}

int Form::getExecGrade() const {
	return exec_grade;
}

bool Form::isSigned() const {
	return is_signed;
}


void Form::beSigned(const Bureaucrat& bureaucrat) {
	
	if (isSigned()) {
		return;
	}

	if (sign_grade < bureaucrat.getGrade()) {
		throw Form::GradeTooLowException();
	} else {
		is_signed = true;
	}
}

/* Exceptions */

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}
