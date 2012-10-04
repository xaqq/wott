/*
 * File:   SslServer.hpp
 * Author: xaqq
 *
 * Created on October 2, 2012, 3:13 PM
 */

#ifndef NETWORK_SSLSERVER_HPP
#define	NETWORK_SSLSERVER_HPP

#include "Wott.hpp"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslError>

namespace Network
{

class SslServer : public QTcpServer
{
    Q_OBJECT
public:
    SslServer();
    SslServer(const SslServer& orig);
    virtual ~SslServer();

    void incomingConnection(int fd);

public slots:
    void onSslError(const QList<QSslError> &e);
    void onDisconnectedSocket();
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onModeChanged(QSslSocket::SslMode m);
    void onReadyRead();
    
private:

};
}
#endif	/* NETWORK_SSLSERVER_HPP */

