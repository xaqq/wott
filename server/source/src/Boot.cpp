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
#include "Log.hpp"
#include "Log/Manager.hpp"
#include "Log/StdLogger.hpp"

void Boot::startInit()
{
    initLog();
}

bool Boot::initLog()
{
    Log::_thread = new QThread;
    Log::_manager = new Log::Manager;
    Log::AbstractLogger *logger = new Log::StdLogger;

    std::cout << "Thread: " << QThread::currentThread() << std::endl;
    Log::_manager->moveToThread(Log::_thread);
    Log::_thread->start();
    logger->registerWithManager();

    Log::info("Logger thread initialized");
    return true;
}