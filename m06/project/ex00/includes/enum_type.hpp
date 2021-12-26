#ifndef ENUM_TYPE_HPP
# define ENUM_TYPE_HPP

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

const char* TypeGetStr(enum Type type);

#endif /* ENUM_TYPE_HPP */
