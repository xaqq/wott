/*
 * File:   AbstractLogger.hpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:26 PM
 */

#ifndef LOG_ABSTRACTLOGGER_HPP
#define	LOG_ABSTRACTLOGGER_HPP

#include "Wott.hpp"
#include "Log.hpp"

namespace Log
{

class AbstractLogger : public QObject
{
    Q_OBJECT
public:
    AbstractLogger();
    AbstractLogger(const AbstractLogger& orig);
    virtual ~AbstractLogger();

    void registerWithManager();

public slots:
    virtual void logInfo(const QString &) = 0;

signals:
    void sigRegister(AbstractLogger *me);

};
}
#endif	/* ABSTRACTLOGGER_HPP */

