#include <string>
#include <cstdlib>
#include <climits>

static bool IntCheckSyntax(const std::string& arg) {
	if (arg.length() == 0) {
		return false;
	}

	size_t i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (i < arg.length()) {
		if (!isdigit(arg[i])) {
			return false;
		}
		i++;
	}
	return true;
}

static bool IntCheckLimit(const std::string& arg) {
	double d = strtod(arg.c_str(), NULL);
	if (d > INT_MAX || d < INT_MIN) {
		return false;
	}
	return true;
}

bool IsInt(const std::string& arg) {
	return IntCheckSyntax(arg) && IntCheckLimit(arg);
}
