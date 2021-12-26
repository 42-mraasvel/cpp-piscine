#include "determine_type.hpp"

bool IsInfNanFloat(const std::string& arg) {
	static const char* vals[] = {
		"nanf",
		"inff",
		"+inff",
		"-inff",
		NULL
	};

	for (int i = 0; vals[i] != NULL; i++) {
		if (arg == vals[i]) {
			return true;
		}
	}
	return false;
}

static bool FloatCheckSyntax(const std::string& arg) {
	if (arg.length() == 0 || arg[arg.length() - 1] != 'f') {
		return false;
	}

	bool dot = false;
	for (size_t i = 0; i + 1 < arg.length(); i++) {
		if (i == 0 && (arg[0] == '-' || arg[0] == '+')) {
			i++;
		}
		if (!isdigit(arg[i])) {
			if (arg[i] != '.' || dot) {
				return false;
			} else {
				dot = true;
			}
		}
	}
	return dot;
}

bool IsFloat(const std::string& arg) {
	return FloatCheckSyntax(arg) || IsInfNanFloat(arg);
}
