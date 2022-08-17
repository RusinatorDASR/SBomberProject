#pragma once

#include <stdint.h>
#include <string>


class FileLoggerSingleton {
public:
	static FileLoggerSingleton& getInstance() {
		static FileLoggerSingleton theInstance;
		return theInstance;
	}
	void __fastcall OpenLogFile(const std::string& FN);

	void CloseLogFile();

	void __fastcall WriteToLog(const std::string& str);

	void __fastcall WriteToLog(const std::string& str, int n);

	void __fastcall WriteToLog(const std::string& str, double d);


private:
	FileLoggerSingleton() {}
	FileLoggerSingleton(const FileLoggerSingleton& root) = delete;
	FileLoggerSingleton& operator= (const FileLoggerSingleton&) = delete;
};