#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm&);

private:

	PresidentialPardonForm();

	virtual void action() const;

};

#endif /* PRESIDENTIALPARDONFORM_HPP */
