/*
 * File:   Manager.cpp
 * Author: xaqq
 *
 * Created on September 18, 2012, 2:19 AM
 */

#include "Network/Manager.hpp"
#include "Log.hpp"
#include "Boot.hpp"
#include "Network/SslClient.hpp"
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QTcpSocket>

Network::Manager::Manager() : QObject(0), _sslSrv(0)
{
}

Network::Manager::Manager(const Network::Manager&) : QObject(0)
{
}

Network::Manager::~Manager()
{
}

void Network::Manager::init(bool &success)
{
    _sslSrv = new Network::SslServer;
    success = _sslSrv->listen(QHostAddress::Any, 31337);
    if (success)
        Log::info("Listening on port" + QString::number(_sslSrv->serverPort()));
}

void Network::Manager::shutdownModule()
{
    Log::info("Network module shutting down...");
}

void Network::Manager::onNewSslClient()
{
    SslClient *s = static_cast<SslClient *> (_sslSrv->nextPendingConnection());
    Client    *c = new Client;
    
    c->setSslClient(s);
    c->setToken(rand());
//    QMetaObject::invokeMethod(MainThread::_manager, "newClient");
}

Network::Client *Network::Manager::clientFromSsl(const SslClient *s)
{
    for (auto c : _clients.toStdList())
    {
        if (c->sslClient() == s)
            return c;
    }
    return 0;
}