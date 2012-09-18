/*
 * File:   StdLogger.hpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:58 PM
 */

#ifndef LOG_STDLOGGER_HPP
#define	LOG_STDLOGGER_HPP

#include "Log/AbstractLogger.hpp"

namespace Log
{

class StdLogger : public AbstractLogger
{
    Q_OBJECT
public:
    StdLogger();
    StdLogger(const StdLogger& orig);
    virtual ~StdLogger();

public slots:
    void logDebug(const QString &s);
    void logInfo(const QString &s);
    void logWarn(const QString &s);
    void logError(const QString &s);

};

};
#endif	/* STDLOGGER_HPP */

