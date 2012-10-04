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
#include <QByteArray>

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
    QSslSocket *serverSocket = new QSslSocket;
    if (serverSocket->setSocketDescriptor(fd))
    {
        QList<QSslCertificate> certs = QSslCertificate::fromPath("/tmp/server.crt");
        if (!(certs.size() >= 1 && !certs.first().isNull()))
        {
            Log::error("No certificate found, dropping connection");
            serverSocket->deleteLater();
            return;
        }

        connect(serverSocket, SIGNAL(modeChanged(QSslSocket::SslMode)),
                this, SLOT(onModeChanged(QSslSocket::SslMode)));
        connect(serverSocket, SIGNAL(encrypted()), Network::_manager, SLOT(newSslClient()));
        connect(serverSocket, SIGNAL(encrypted()), this, SLOT(LOLSLOT()));
        connect(serverSocket, SIGNAL(sslErrors(const QList<QSslError> &)),
                this, SLOT(onSslError(const QList<QSslError> &)));
        connect(serverSocket, SIGNAL(disconnected()), this, SLOT(onDisconnectedSocket()));
        connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
                SLOT(onSocketError(QAbstractSocket::SocketError)));

        serverSocket->setLocalCertificate(certs.first());
        serverSocket->setPrivateKey("/tmp/server.key");
        serverSocket->setProtocol(QSsl::TlsV1SslV3);
        serverSocket->setPeerVerifyMode(QSslSocket::VerifyNone);
        serverSocket->startServerEncryption();
        connect(serverSocket, SIGNAL(readyRead()), this,
                SLOT(onReadyRead()));
        addPendingConnection(serverSocket);
    }
    else
    {
        delete serverSocket;
    }
}

void Network::SslServer::onModeChanged(QSslSocket::SslMode m)
{
    Log::debug("New socket state = " + QString::number(m));
}

void Network::SslServer::onSslError(const QList<QSslError> &e)
{
    Log::error("SSL ERROR");
}

void Network::SslServer::onDisconnectedSocket()
{
    Log::warn("socket disconnected");
}

void Network::SslServer::onSocketError(QAbstractSocket::SocketError socketError)
{
    QTcpSocket *s = qobject_cast<QTcpSocket *>(QObject::sender());
    if (s)
        Log::error("socket error : " + s->errorString());
}

void Network::SslServer::onReadyRead()
{
    QSslSocket *s = qobject_cast<QSslSocket *>(QObject::sender());
    
    if (s)
        Log::debug("Read...: " + QString(s->readAll().constData()));
}