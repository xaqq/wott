/*
 * File:   Log.cpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 10:32 PM
 */

#include "Log.hpp"
#include "Log/Manager.hpp"

QThread *Log::_thread = 0;
Log::Manager *Log::_manager = 0;

void Log::debug(const QString &s)
{
    Log::_manager->logDebug(s);
}

void Log::info(const QString &s)
{
    Log::_manager->logInfo(s);
}

void Log::warn(const QString &s)
{
    Log::_manager->logWarn(s);
}

void Log::error(const QString &s)
{
    Log::_manager->logError(s);
}
