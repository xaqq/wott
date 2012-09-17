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
}

void    Log::StdLogger::logInfo(const QString &s)
{
    std::cout << "[INFO] " << s.toStdString() << std::endl;
}

