#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("presidential pardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: Form("presidential pardon", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& from)
	: Form("presidential pardon", from.getTarget(), 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	(void)rhs;
	return *this;
}

void PresidentialPardonForm::action() const {
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
