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
#include "Network.hpp"

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
    if (!initNetwork())
    {
        std::cerr << "Aborting boot" << std::endl;
        QMetaObject::invokeMethod(Sql::_manager, "shutdownModule", Qt::BlockingQueuedConnection);
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

    Sql::_manager->moveToThread(Sql::_thread);
    Sql::_thread->start();

    QMetaObject::invokeMethod(Sql::_manager, "init", Qt::BlockingQueuedConnection, Q_ARG(bool &, res));
    if (!res)
        Log::error("Sql module failed to start. Stopping server.");
    return res;
}

bool Boot::initNetwork()
{
    bool res;

    Network::_thread = new QThread;
    Network::_manager = new Network::Manager;

    Network::_manager->moveToThread(Network::_thread);
    Network::_thread->start();

    QMetaObject::invokeMethod(Network::_manager, "init", Qt::BlockingQueuedConnection, Q_ARG(bool &, res));
    if (!res)
        Log::error("Network module failed to start. Stopping server.");
    return res;
}