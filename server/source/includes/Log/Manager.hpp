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
 * \brief Manager class for logging debug, warning or error.
 *
 * The Log manager class handle a list of Logger instance (derived class from
 * Log::AbstractLogger\n
 * When the newLogger slot is called, the manager connects the logger slot
 * to its signal sigLogInfo.
 */
class Manager : public ::QObject
{
    Q_OBJECT

public:
    Manager();
    virtual ~Manager();

    /**
     * Dispatch the log message to the logger by emitting sigLogInfo.
     * @param Message
     */
    void logInfo(const QString &s);

public slots:
    /**
     * Called when a new logger want to be registered. This slot is
     * connected to Log::AbstractLogger::sigRegister using a BlockingQueued
     * connection
     * @param logger
     */
    void newLogger(AbstractLogger *logger);

signals:
    /**
     * Emitted when a log message with priority "info" is send.
     * Loggers' logInfo slot will be notified.
     * @param Message
     */
    void sigLogInfo(const QString &);

private:
    Manager(const Manager& orig);
    QList<AbstractLogger *> _loggers;
};
};

#endif	/* LOG_MANAGER_H */

