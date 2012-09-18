/*
 * File:   AbstractLogger.hpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:26 PM
 */

#ifndef LOG_ABSTRACTLOGGER_HPP
#define	LOG_ABSTRACTLOGGER_HPP

#include "Wott.hpp"

namespace Log
{

class AbstractLogger : public QObject
{
    Q_OBJECT
public:
    AbstractLogger();
    AbstractLogger(const AbstractLogger& orig);
    virtual ~AbstractLogger();

    /**
     * Register the logger with the manager.
     * This call is blocking, because the signal it emits is connected
     * with the logger manager that lives in the log's thread and the connection
     * is BlockingQueued.\n This ensure that there is no race condition
     * when adding a new logger and logging someting right after that.
     */
    void registerWithManager();

public slots:
    virtual void logDebug(const QString &) = 0;
    virtual void logInfo(const QString &) = 0;
    virtual void logWarn(const QString &) = 0;
    virtual void logError(const QString &) = 0;

signals:
    /**
     * \brief Emitted when Log::AbstractLogger::registerWithManager is called.
     * @param me
     */
    void sigRegister(AbstractLogger *me);

};
}
#endif	/* ABSTRACTLOGGER_HPP */

