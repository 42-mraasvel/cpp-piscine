#include <fstream>
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("shrubbery creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: Form("shrubbery creation", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& from)
	: Form("shrubbery creation", from.getTarget(), 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	(void)rhs;
	return *this;
}

void ShrubberyCreationForm::writeTrees(std::ofstream& out, int htrees) const {
	const std::string tree = \
	"      /\\      "
	"     /\\*\\     "
	"    /\\O\\*\\    "
	"   /*/\\/\\/\\   "
	"  /\\O\\/\\*\\/\\  "
	" /\\*\\/\\*\\/\\/\\ "
	"/\\O\\/\\/*/\\/O/\\"
	"      ||      "
	"      ||      "
	"      ||      ";

	const int LINE_SIZE = 14;
	const int NUM_LINES = 10;

	for (int i = 0; i < NUM_LINES; i++) {
		for (int k = 0; k < htrees; k++) {
			for (int j = 0; j < LINE_SIZE; j++) {
				out << tree[j + i * LINE_SIZE];
			}
			out << ' ';
		}
		out << std::endl;
	}
}

void ShrubberyCreationForm::action() const {

	std::ofstream out;
	std::string outfile = getTarget() + "_shrubbery";
	out.open(outfile.c_str(), std::ios_base::trunc | std::ios_base::out);

	if (!out.is_open()) {
		throw std::runtime_error("cannot open file: " + outfile);
	}

	const int HTREES = 5;
	const int VTREES = 5;

	for (int i = 0; i < VTREES; i++) {
		writeTrees(out, HTREES);
		out << std::endl;
	}

	out.close();
}
