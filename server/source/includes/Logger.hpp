/*
 * File:   Logger.hpp
 * Author: xaqq
 *
 * Created on September 8, 2012, 11:10 PM
 */

#ifndef LOGGER_HPP
#define	LOGGER_HPP

#include <QObject>

class Logger : public QObject
{
    Q_OBJECT
public:
    Logger();
    Logger(const Logger& orig);
    virtual ~Logger();

    static bool Info(Logger *me, const QString &str);
    // used by static method
    signals:
        void logInfo(const QString &str);

    private slots:
        void receiveLogInfo(const QString &str);

};

#endif	/* LOGGER_HPP */

