#pragma once

#include <stdint.h>
#include <string>
#include "FileLoggerSingleton.h"



extern int countLog;
class LoggerSingleton {
public:
	static LoggerSingleton& getInstance() {
		static LoggerSingleton theInstance;
		return theInstance;
	}

	void __fastcall OpenLogFile(const std::string& FN);

	void CloseLogFile();

	void __fastcall WriteToLog(const std::string& str);

	void __fastcall WriteToLog(const std::string& str, int n);

	void __fastcall WriteToLog(const std::string& str, double d);

private:
	LoggerSingleton() {}
	LoggerSingleton(const LoggerSingleton& root) = delete;
	LoggerSingleton& operator= (const LoggerSingleton&) = delete;
	FileLoggerSingleton *realFileLoggerSingleton;
	~LoggerSingleton() {
		delete realFileLoggerSingleton;
	}
};