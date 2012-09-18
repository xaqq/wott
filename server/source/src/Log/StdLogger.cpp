/*
 * File:   StdLogger.cpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:58 PM
 */

#include "Log/StdLogger.hpp"
#include <iostream>

Log::StdLogger::StdLogger() : Log::AbstractLogger()
{
}

Log::StdLogger::StdLogger(const Log::StdLogger&) : Log::AbstractLogger()
{
}

Log::StdLogger::~StdLogger()
{
    std::cout << "\e[0;m" << std::endl;
}

void Log::StdLogger::logInfo(const QString &s)
{
    std::cout << "\e[1;34m" << "[INFO] " << s.toStdString() << std::endl;
}

void Log::StdLogger::logDebug(const QString& s)
{
    std::cout << "[DEBUG] " << s.toStdString() << std::endl;
}

void Log::StdLogger::logWarn(const QString& s)
{
    std::cout << "\e[1;33m" << "[WARN] " << s.toStdString() << std::endl;
}

void Log::StdLogger::logError(const QString& s)
{
    std::cout << "\e[1;31m" << "[ERROR] " << s.toStdString() << std::endl;
}