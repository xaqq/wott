/*
 * File:   Manager.cpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 10:32 PM
 */

#include <qt4/QtCore/qobject.h>

#include "Log/Manager.hpp"
using namespace Log;

Manager::Manager() : QObject(0)
{
}

Manager::Manager(const Manager&) : QObject(0)
{
}

Manager::~Manager()
{
}

void Manager::logDebug(const QString& s)
{
    emit sigLogDebug(s);
}

void Manager::logInfo(const QString& s)
{
    emit sigLogInfo(s);
}

void Manager::logWarn(const QString& s)
{
    emit sigLogWarn(s);
}

void Manager::logError(const QString& s)
{
    emit sigLogError(s);
}

void Manager::newLogger(AbstractLogger* ptr)
{
    connect(this, SIGNAL(sigLogDebug(const QString &)),
            ptr, SLOT(logDebug(const QString &)));
    connect(this, SIGNAL(sigLogInfo(const QString &)),
            ptr, SLOT(logInfo(const QString &)));
    connect(this, SIGNAL(sigLogWarn(const QString &)),
            ptr, SLOT(logWarn(const QString &)));
    connect(this, SIGNAL(sigLogError(const QString &)),
            ptr, SLOT(logError(const QString &)));
    _loggers.append(ptr);
    emit sigLogInfo("New logger registered");
}

void Manager::shutdownModule()
{
    Log::info("Log module shutting down...");

    for (QList<AbstractLogger *>::iterator it = _loggers.begin();
            it != _loggers.end();
            it = _loggers.erase(it))
    {
        delete (*it);
    }
}