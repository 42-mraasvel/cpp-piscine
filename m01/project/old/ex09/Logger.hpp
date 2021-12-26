#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>

class Logger {

public:

	Logger(std::string const& logfile_name);

	void log(std::string const& dest, std::string const& message);

private:

	static std::string GetTimestampString(void);

	void logToConsole(std::string const& output) const;
	void logToFile(std::string const& output) const;
	std::string makeLogEntry(std::string const& message) const;

	std::string const _logfile_name;

};

#endif /* LOGGER_HPP */
