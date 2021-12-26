#include "Logger.hpp"

void LogBoth(Logger& logger, std::string msg) {
	logger.log("Console", msg);
	logger.log("File", msg);
}

int main(void) {

	const std::string LOGFILE = "output.log";

	Logger logger(LOGFILE);

	LogBoth(logger, "PROGRAM START");
	LogBoth(logger, "INVALID INPUT");
	LogBoth(logger, "DEBUG MESSAGE");
	LogBoth(logger, "ERROR MESSAGE");
	LogBoth(logger, "PROGRAM END");

	/* Invalid Destination Example */
	logger.log("NOT AN ACTION", "MESSAGE THAT NEVER SHOWS");
	return 0;
}
