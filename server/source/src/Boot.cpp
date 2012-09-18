/*
 * File:   Boot.cpp
 * Author: xaqq
 *
 * Created on September 8, 2012, 7:27 PM
 */

#include "Boot.hpp"
#include <iostream>
#include <qt4/QtCore/qcoreapplication.h>
#include <QThread>
#include <qt4/QtCore/qtimer.h>
#include <qt4/QtGui/qabstractitemview.h>
#include "Log.hpp"
#include "Sql.hpp"

void Boot::startInit()
{
    if (!initLog())
    {
        std::cerr << "Aborting boot" << std::endl;
        abort();
    }
    if (!initSql())
    {
        std::cerr << "Aborting boot" << std::endl;
        QMetaObject::invokeMethod(Log::_manager, "shutdownModule", Qt::BlockingQueuedConnection);
        abort();
    }
}

bool Boot::initLog()
{
    Log::_thread = new QThread;
    Log::_manager = new Log::Manager;
    Log::AbstractLogger *logger = new Log::StdLogger;

    Log::_manager->moveToThread(Log::_thread);
    Log::_thread->start();
    logger->registerWithManager();

    Log::info("Logger thread initialized");
    return true;
}

bool Boot::initSql()
{
    bool res;

    Sql::_thread = new QThread;
    Sql::_manager = new Sql::Manager;

    std::cout << "Thread: " << QThread::currentThread() << std::endl;
    Sql::_manager->moveToThread(Sql::_thread);
    Sql::_thread->start();

    QMetaObject::invokeMethod(Sql::_manager, "init", Qt::BlockingQueuedConnection, Q_ARG(bool &, res));
    if (!res)
        Log::error("Sql module failed to start. Stopping server.");
    return res;
}