/*
 * File:   SslServer.cpp
 * Author: xaqq
 *
 * Created on October 2, 2012, 3:13 PM
 */

#include "Network.hpp"
#include "Network/SslServer.hpp"
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslCipher>

#include "Log.hpp"

Network::SslServer::SslServer() : QTcpServer(0)
{
}

Network::SslServer::SslServer(const SslServer& orig) : QTcpServer(0)
{
}

Network::SslServer::~SslServer()
{
}

void Network::SslServer::incomingConnection(int fd)
{
    Log::warn("here");
    QSslSocket *serverSocket = new QSslSocket;
    if (serverSocket->setSocketDescriptor(fd))
    {
        serverSocket->setLocalCertificate("/tmp/key");
        serverSocket->setPrivateKey("/tmp/sslserver.pem");
        serverSocket->setProtocol(QSsl::SslV3);

        serverSocket->setPeerVerifyMode(QSslSocket::VerifyNone);
//        connect(serverSocket, SIGNAL(encrypted()), Network::_manager, SLOT(newSslClient()));
        connect(serverSocket, SIGNAL(encrypted()), this, SLOT(LOLSLOT()));
        connect(serverSocket, SIGNAL(sslErrors(const QList<QSslError> &)),
                this, SLOT(onSslError(const QList<QSslError> &)));
        connect(serverSocket, SIGNAL(disconnected()), this, SLOT(OnDisconnectedSocket()));
        connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(OnSocketError(QAbstractSocket::SocketError)));
        Log::warn("s state = " + QString::number(serverSocket->state()));

        serverSocket->startServerEncryption();
//        addPendingConnection(serverSocket);
    }
    else
    {
        delete serverSocket;
    }
}

void Network::SslServer::onSslError(const QList<QSslError> &e)
{
    Log::error("SSL ERROR");
}

void Network::SslServer::OnDisconnectedSocket()
{
    Log::warn("socket disconnected");
}

void Network::SslServer::OnSocketError(QAbstractSocket::SocketError socketError)
{
    QTcpSocket *s = qobject_cast<QTcpSocket *>(QObject::sender());
    Log::debug("nb ciphers = " + QString::number(QSslSocket::defaultCiphers().size()));
    for (auto i : QSslSocket::defaultCiphers().toStdList())
    {
        Log::debug("Cipher: " + i.name());
    }
    Log::error("socket error : " + s->errorString());
}

void Network::SslServer::LOLSLOT()
{
    Log::error("LOLSLOT");
}