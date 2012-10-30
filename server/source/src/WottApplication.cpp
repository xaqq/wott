/*
 * File:   WootApplication.cpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:13 PM
 */

#include <QThread>
#include "WottApplication.hpp"
#include "Log.hpp"
#include "Sql.hpp"
#include "Network.hpp"
#include <iostream>
#include <unistd.h>
#include <qt4/QtCore/qobjectdefs.h>

WottApplication::~WottApplication()
{
}

bool WottApplication::notify(QObject *rec, QEvent *ev)
{
    try
    {
        return QCoreApplication::notify(rec, ev);
    }
    catch (char const *str)
    {
        std::cerr << "EXCEPTION: " << str << std::endl;
        return false;
    }
    catch (int i)
    {
        std::cout << "Notify in thread " << QThread::currentThread() << std::endl;
        std::cerr << "Int exception" << i << std::endl;
        return false;
    }
    catch (...)
    {
        std::cerr << "Unknown exception!" << std::endl;
        abort();
    }
}

void WottApplication::shutdownServer()
{
    QMetaObject::invokeMethod(Sql::_manager, "shutdownModule", Qt::BlockingQueuedConnection);
    QMetaObject::invokeMethod(Log::_manager, "shutdownModule", Qt::BlockingQueuedConnection);
    QMetaObject::invokeMethod(Network::_manager, "shutdownModule", Qt::BlockingQueuedConnection);
    std::cout << "Server shutdown complete" << std::endl;
    exit(0);
}