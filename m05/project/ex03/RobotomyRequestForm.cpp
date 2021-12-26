#include <cstdlib>
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
	: Form("robotomy request", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: Form("robotomy request", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& from)
	: Form("robotomy request", from.getTarget(), 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	(void)rhs;
	return *this;
}

void RobotomyRequestForm::action() const {
	std::cout << "* DRILLING NOISES *" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << "Failed to robotomize " << getTarget() << std::endl;
	} else {
		std::cout << "Successfully robotomized " << getTarget() << std::endl;
	}
}
