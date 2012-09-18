/*
 * File:   sigIntDaemon.cpp
 * Author: xaqq
 *
 * Created on September 19, 2012, 12:48 AM
 */

#include "sigDaemon.hpp"
#include "WottApplication.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <Log.hpp>

int SigDaemon::sigintFd[2];

SigDaemon::SigDaemon()
: QObject(0)
{
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigintFd))
        qFatal("Couldn't create HUP socketpair");

    snInt = new QSocketNotifier(sigintFd[1], QSocketNotifier::Read, this);
    connect(snInt, SIGNAL(activated(int)), this, SLOT(handleSigInt()));
}

SigDaemon::~SigDaemon()
{
    delete snInt;
}

void SigDaemon::intSignalHandler(int)
{
    char a = 1;
    ::write(sigintFd[0], &a, sizeof (a));
}

void SigDaemon::handleSigInt()
{
    snInt->setEnabled(false);
    char tmp;
    ::read(sigintFd[1], &tmp, sizeof (tmp));

    Log::warn("SIGINT caugth. Asking Wott server to terminate.");
    QTimer::singleShot(0, WottApplication::instance(), SLOT(shutdownServer()));
    snInt->setEnabled(true);
}
