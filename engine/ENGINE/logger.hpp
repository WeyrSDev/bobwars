#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

namespace logger
{
	void INFO(std::string output);

	void INFO(std::string output, int);

	void WARNING(std::string output);

	void ERROR(std::string output);

	void SILENT(std::string type, std::string output);

	void CUSTOM(std::string type, std::string output);

	void BREAK();

	void setOutputDir(const std::string dir);
	void setOutputDir(const std::string dir, const std::string filename);
}

namespace loggerv2
{
	extern int logLevel;
	/* 0 = no logging
	// 1 = log to files only
	// 2 = only print info, warnings, and errors
	// 3 = 1 + light debug messages
	// 4 = print all debug messages */

	extern std::string logLocation;

	void logToFile(std::string message);

	void logToConsole(std::string message);

	void INFO(std::string message);

	void DEBUG(std::string message);

	// i plan to do something with that extra arg, i just don't know what yet.
	void log(std::string type, std::string message, int level);
}

class Logger3
{
public:
	Logger3(std::string logOutputDir_);
	~Logger3();

	void log(std::string type, std::string message);
	void info(std::string message);
	void warn(std::string message);
	void error(std::string message);

private:
	void writeLog(std::string monitor);
	std::string logOutputDir;
};

#endif /* LOGGER_HPP */
