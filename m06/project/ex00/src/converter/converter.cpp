#include "converter.hpp"

/* Constructors/Destructors */
Converter::Converter() {}

Converter::Converter(const std::string& arg, enum Type type)
	: str(arg) {
	for (int i = 0; i < static_cast<int>(UNKNOWN); i++) {
		valid[i] = true;
	}

	static const convertf_t converters[] = {
		&Converter::ConvertChar,
		&Converter::ConvertInt,
		&Converter::ConvertFloat,
		&Converter::ConvertDouble,
	};

	if (static_cast<int> (type) > 3) {
		throw std::exception();
	}

	(this->*(converters[static_cast<int> (type)]))();
}

Converter::Converter(const Converter& from)
	: str(from.str) {
	*this = from;
}

Converter::~Converter() {}

/* Operators */
Converter& Converter::operator=(const Converter& rhs) {
	if (this == &rhs) {
		return *this;
	}

	c = rhs.c;
	n = rhs.n;
	f = rhs.f;
	d = rhs.d;
	for (int i = 0; i < 4; i++) {
		valid[i] = rhs.valid[i];
	}
	return *this;
}
