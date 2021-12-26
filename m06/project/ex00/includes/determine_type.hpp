#ifndef DETERMINE_TYPE_HPP
# define DETERMINE_TYPE_HPP

# include <string>
# include "enum_type.hpp"

typedef bool (*isfunc_t)(const std::string&);

enum Type DetermineType(const std::string& arg);

bool IsInt(const std::string& arg);
bool IsChar(const std::string& arg);
bool IsFloat(const std::string& arg);
bool IsDouble(const std::string& arg);

bool IsInfNanFloat(const std::string& arg);
bool IsInfNanDouble(const std::string& arg);

#endif /* DETERMINE_TYPE_HPP */
