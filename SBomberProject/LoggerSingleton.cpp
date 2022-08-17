#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>


#include "FileLoggerSingleton.h"
#include "LoggerSingleton.h"

using namespace std;


int countLog = 0;

void __fastcall LoggerSingleton::OpenLogFile(const string& FN)
{
	if (!LoggerSingleton::realFileLoggerSingleton) {
		LoggerSingleton::realFileLoggerSingleton = &FileLoggerSingleton::getInstance();
	}
	LoggerSingleton::realFileLoggerSingleton->getInstance().OpenLogFile(FN);
}

void LoggerSingleton::CloseLogFile()
{
	LoggerSingleton::realFileLoggerSingleton->getInstance().CloseLogFile();
}


void __fastcall LoggerSingleton::WriteToLog(const string& str)
{

	LoggerSingleton::realFileLoggerSingleton->getInstance().WriteToLog(to_string(++countLog) + ": " + str);
}

void __fastcall LoggerSingleton::WriteToLog(const string& str, int n)
{
	LoggerSingleton::realFileLoggerSingleton->getInstance().WriteToLog(to_string(++countLog) + ": " + str, n);
}

void __fastcall LoggerSingleton::WriteToLog(const string& str, double d)
{
	LoggerSingleton::realFileLoggerSingleton->getInstance().WriteToLog(to_string(++countLog) + ": " + str, d);
}