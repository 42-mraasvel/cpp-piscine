#include <string>

bool IsChar(const std::string& arg) {
	if (arg.length() == 1 && !isdigit(arg[0])) {
		return true;
	}
	return false;
}
