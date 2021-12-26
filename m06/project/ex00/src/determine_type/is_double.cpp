#include <string>

bool IsInfNanDouble(const std::string& arg) {
	static const char* vals[] = {
		"nan",
		"inf",
		"+inf",
		"-inf",
		NULL
	};

	for (int i = 0; vals[i] != NULL; i++) {
		if (arg == vals[i]) {
			return true;
		}
	}
	return false;
}

static bool DoubleCheckSyntax(const std::string& arg) {
	if (arg.length() == 0) {
		return false;
	}

	bool dot = false;
	for (size_t i = 0; i < arg.length(); i++) {
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

bool IsDouble(const std::string& arg) {
	return DoubleCheckSyntax(arg) || IsInfNanDouble(arg);
}
