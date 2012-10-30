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
#include "Network/SslClient.hpp"

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
    SslClient *clientSocket = new SslClient;
    if (clientSocket->setSocketDescriptor(fd))
    {
        QList<QSslCertificate> certs = QSslCertificate::fromPath("/tmp/server.crt");
        if (!(certs.size() >= 1 && !certs.first().isNull()))
        {
            Log::error("No certificate found, dropping connection");
            clientSocket->deleteLater();
            return;
        }

        connect(clientSocket, SIGNAL(modeChanged(QSslSocket::SslMode)),
                this, SLOT(onModeChanged(QSslSocket::SslMode)));
        connect(clientSocket, SIGNAL(encrypted()), clientSocket, SLOT(onEncrypted()));
        connect(clientSocket, SIGNAL(encrypted()), Network::_manager, SLOT(onNewSslClient()));
        connect(clientSocket, SIGNAL(sslErrors(const QList<QSslError> &)),
                this, SLOT(onSslError(const QList<QSslError> &)));
        connect(clientSocket, SIGNAL(disconnected()), this, SLOT(onDisconnectedSocket()));
        connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)),
                SLOT(onSocketError(QAbstractSocket::SocketError)));

        clientSocket->setLocalCertificate(certs.first());
        clientSocket->setPrivateKey("/tmp/server.key");
        clientSocket->setProtocol(QSsl::TlsV1SslV3);
        clientSocket->setPeerVerifyMode(QSslSocket::VerifyNone);
        clientSocket->startServerEncryption();

        addPendingConnection(clientSocket);
    }
    else
    {
        delete clientSocket;
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
    SslClient *s = qobject_cast<SslClient *>(QObject::sender());

    Network::_manager->clientFromSsl(s)->setSslClient(0);
    s->deleteLater();
}

void Network::SslServer::onSocketError(QAbstractSocket::SocketError socketError)
{
    QTcpSocket *s = qobject_cast<QTcpSocket *>(QObject::sender());
    if (s)
        Log::error("socket error : " + s->errorString());
}
