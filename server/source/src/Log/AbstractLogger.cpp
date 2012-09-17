/*
 * File:   AbstractLogger.cpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:26 PM
 */

#include <qt4/QtCore/qobject.h>
#include "Log/AbstractLogger.hpp"
#include "Log/Manager.hpp"

Log::AbstractLogger::AbstractLogger() : ::QObject(0)
{
    connect(this, SIGNAL(sigRegister(AbstractLogger *)),
            Log::_manager,
            SLOT(newLogger(AbstractLogger *)),
            Qt::BlockingQueuedConnection);
}

Log::AbstractLogger::AbstractLogger(const Log::AbstractLogger&) : ::QObject(0)
{
}

Log::AbstractLogger::~AbstractLogger()
{
}

void Log::AbstractLogger::registerWithManager()
{
    moveToThread(Log::_thread);
    emit sigRegister(this);
}

