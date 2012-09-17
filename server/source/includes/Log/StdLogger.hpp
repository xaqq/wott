/*
 * File:   StdLogger.hpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:58 PM
 */

#ifndef LOG_STDLOGGER_HPP
#define	LOG_STDLOGGER_HPP

#include "Log/AbstractLogger.hpp"
#include "AbstractLogger.hpp"

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
    void logInfo(const QString &);
private:

};

};
#endif	/* STDLOGGER_HPP */

