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
      QList<QSslCertificate> certs = QSslCertificate::fromPath("/tmp/server.crt");
      qDebug() << "Loaded # certs from disk:" << certs.size();
      qDebug() << "Cert is null?" << certs.first().isNull();


      connect(serverSocket, SIGNAL(modeChanged(QSslSocket::SslMode)),
	      this, SLOT(OnModeChanged(QSslSocket::SslMode)));
      serverSocket->setLocalCertificate(certs.first());
      serverSocket->setPrivateKey("/tmp/server.key");
      serverSocket->setProtocol(QSsl::TlsV1SslV3);

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

void Network::SslServer::OnModeChanged(QSslSocket::SslMode m)
{
  Log::warn("New socket state = " + QString::number(m));
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
