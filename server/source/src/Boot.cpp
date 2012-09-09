/*
 * File:   Boot.cpp
 * Author: xaqq
 *
 * Created on September 8, 2012, 7:27 PM
 */

#include "Boot.hpp"
#include <QThread>
#include "Logger.hpp"
#include        <iostream>
#include <QString>
#include <qt4/QtCore/qobject.h>

BootPtr Boot::_me(0);

Boot::Boot()
{
}

BootPtr Boot::instance()
{
    if (!_me)
        _me = BootPtr(new Boot);
    return _me;
}

Boot::Boot(const Boot& orig)
{
}

Boot::~Boot()
{

}

bool    Boot::init()
{
    QThread *logThread = new QThread;
    Logger *l = new Logger;

    l->moveToThread(logThread);
    logThread->start();
    QString     s("Salut");
    Logger::Info(l, s);

    return false;
}

bool    Boot::unload()
{
   _me = BootPtr(0);
}