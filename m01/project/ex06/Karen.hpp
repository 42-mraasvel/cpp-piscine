#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

enum KarenFilters {
	DEBUG = 0,
	INFO = 1,
	WARNING = 2,
	ERROR = 3
};

class Karen {

public:

	void complain(std::string level);

private:

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

};

#endif /* KAREN_HPP */
