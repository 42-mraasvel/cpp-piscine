#include <iostream>
#include <fstream>
#include "Logger.hpp"


Logger::Logger(std::string const& logfile_name)
	: _logfile_name(logfile_name) {}

void Logger::log(std::string const& dest, std::string const& message) {

	void (Logger::*log_functions[2])(std::string const&) const = {
		&Logger::logToConsole,
		&Logger::logToFile
	};

	static std::string types[2] = {
		"Console",
		"File"
	};

	for (int i = 0; i < 2; i++) {
		if (dest == types[i]) {
			(this->*(log_functions[i]))(makeLogEntry(message));
		}
	}
}


std::string Logger::GetTimestampString(void) {

	time_t rawtime;
	struct tm *timeinfo;
	char buffer[50];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	// YEAR MONTH DAY _ HOUR MINUTE SECOND
	strftime(buffer, 50, "[%Y%m%d_%H%M%S]", timeinfo);
	return std::string(buffer);
}

void Logger::logToConsole(std::string const& message) const {
	std::clog << message << std::endl;
}

void Logger::logToFile(std::string const& message) const {

	std::ofstream ofs;
	ofs.open(_logfile_name.c_str(), std::ios::out | std::ios::app);
	if (!ofs.is_open()) {
		std::cerr << "ERROR: failed to open log file: " << _logfile_name << std::endl;
		return;
	}
	ofs << message << std::endl;
	ofs.close();

}

std::string Logger::makeLogEntry(std::string const& message) const {
	std::string entry;
	entry = GetTimestampString() + " MESSAGE: " + message;
	return entry;
}
