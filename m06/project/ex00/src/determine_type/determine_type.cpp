#include "determine_type.hpp"

const char* TypeGetStr(enum Type type) {
	static const char* types[] = {
		"char",
		"int",
		"float",
		"double",
		"UNKNOWN"
	};

	return types[(int)type];
}

typedef bool (*isfunc_t)(const std::string&);

enum Type DetermineType(const std::string& arg) {
	static const isfunc_t is_functions[] = {
		IsChar,
		IsInt,
		IsFloat,
		IsDouble
	};

	for (int i = 0; i < static_cast<int> (UNKNOWN); i++) {
		if (is_functions[i](arg)) {
			return static_cast<enum Type> (i);
		}
	}
	return UNKNOWN;
}
