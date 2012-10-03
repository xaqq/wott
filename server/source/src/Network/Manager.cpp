/*
 * File:   Manager.cpp
 * Author: xaqq
 *
 * Created on September 18, 2012, 2:19 AM
 */

#include "Network/Manager.hpp"
#include "Log.hpp"
#include "Boot.hpp"
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
//    connect(_sslSrv, SIGNAL(newReadyConnection()), this, SLOT(newSslClient()));
    success = _sslSrv->listen(QHostAddress::Any, 4242);
    if (success)
        Log::info("Listening on port" + QString::number(_sslSrv->serverPort()));
}

void Network::Manager::shutdownModule()
{
    Log::info("Network module shutting down...");
}

void Network::Manager::newSslClient()
{
    QTcpSocket *clientConnection = _sslSrv->nextPendingConnection();
//
//        QObject::connect(clientConnection, SIGNAL(disconnected()),
//                       clientConnection, SLOT(deleteLater()));

    QSslSocket *ssl;

    ssl = dynamic_cast<QSslSocket *> (clientConnection);
    if (!ssl)
        Log::warn("NO SSL SOCKET IN NEW SSL CLIENT");
    else
        Log::info("OK SSL SOCKET");
}
