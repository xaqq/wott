/*
 * File:   Logger.cpp
 * Author: xaqq
 *
 * Created on September 8, 2012, 11:10 PM
 */

#include <qt4/QtCore/qobjectdefs.h>

#include "Logger.hpp"
#include <iostream>
#include <qt4/QtCore/qstring.h>

Logger::Logger() : QObject(0)
{
    connect(this, SIGNAL(logInfo(QString)), this, SLOT(receiveLogInfo(QString)));

}

Logger::Logger(const Logger& orig)
{
}

Logger::~Logger()
{

}

bool Logger::Info(Logger *me, const QString& str)
{
    emit(me->logInfo(str));
}

void    Logger::receiveLogInfo(const QString& str)
{
    std::cout << "Hey" << str.toStdString() << std::endl;
}
