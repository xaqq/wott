/*
 * File:   Manager.h
 * Author: xaqq
 *
 * Created on September 17, 2012, 10:32 PM
 */

#ifndef LOG_MANAGER_H
#define	LOG_MANAGER_H

#include "Wott.hpp"
#include "Log/AbstractLogger.hpp"
#include <QString>
#include <QList>

namespace Log
{

/**
 * Manager class for logging debug, warning or error
 */
class Manager : public ::QObject
{
    Q_OBJECT

public:
    Manager();
    virtual ~Manager();
    void logInfo(const QString &s);

public slots:
    void newLogger(AbstractLogger *ptr);

signals:
    void sigLogInfo(const QString &);

private:
    Manager(const Manager& orig);
    QList<AbstractLogger *> _loggers;
};
};

#endif	/* LOG_MANAGER_H */

