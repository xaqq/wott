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

void Manager::logInfo(const QString& s)
{
    emit sigLogInfo(s);
}

void Manager::newLogger(AbstractLogger* ptr)
{
    connect(this, SIGNAL(sigLogInfo(const QString &)),
            ptr, SLOT(logInfo(const QString &)));
    _loggers.append(ptr);
    emit sigLogInfo("New logger registered");
}