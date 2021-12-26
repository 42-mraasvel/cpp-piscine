#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm&);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm&);

private:

	RobotomyRequestForm();

	virtual void action() const;

};

#endif /* ROBOTOMYREQUESTFORM_HPP */
