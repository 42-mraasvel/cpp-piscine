#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

private:

	ShrubberyCreationForm();

	virtual void action() const;
	void writeTrees(std::ofstream& out, int htrees) const;

};

#endif /* SHRUBBERYCREATIONFORM_HPP */
