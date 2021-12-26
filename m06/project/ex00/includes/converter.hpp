#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include "enum_type.hpp"

class Converter {
public:
/* Constructors/Destructors */
	Converter(const std::string& arg, enum Type type);
	Converter(const Converter& from);
	~Converter();

/* Operators */
	Converter& operator=(const Converter& rhs);

/* Member Functions */
	void Print() const;

private:
	Converter();

/* Conversion Member Functions */

	typedef void (Converter::*convertf_t)();

	void ConvertChar();
	void ConvertInt();
	void ConvertFloat();
	void ConvertDouble();

/* Printing Member Functions */

	typedef void (Converter::*print_t)() const;

	void PrintChar() const;
	void PrintInt() const;
	void PrintFloat() const;
	void PrintDouble() const;
	void PrintImpossible(const std::string& prefix) const;

/* Attributes */
	const std::string str;
	bool	valid[4];
	int		n;
	char	c;
	float	f;
	double	d;
};

#endif /* CONVERTER_HPP */
