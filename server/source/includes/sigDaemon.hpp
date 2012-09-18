/*
 * File:   sigIntDaemon.hpp
 * Author: xaqq
 *
 * Created on September 19, 2012, 12:48 AM
 */

#ifndef SIGINTDAEMON_HPP
#define	SIGINTDAEMON_HPP

#include <QObject>
#include <QSocketNotifier>

class SigDaemon : public QObject
{
    Q_OBJECT

public:
    SigDaemon();
    ~SigDaemon();

    // Unix signal handlers.
    static void intSignalHandler(int unused);

public slots:
    // Qt signal handlers.
    void handleSigInt();

private:
    static int sigintFd[2];

    QSocketNotifier *snInt;
};
#endif	/* SIGINTDAEMON_HPP */

