/* 
 * File:   SslClient.hpp
 * Author: xaqq
 *
 * Created on October 4, 2012, 2:04 PM
 */

#ifndef NETWORK_SSLCLIENT_HPP
#define	NETWORK_SSLCLIENT_HPP
#include <QtNetwork/QSslSocket>

namespace Network
{

/**
 * \brief Represent a Ssl connection with a client.
 */
class SslClient : public QSslSocket
{
    Q_OBJECT
public:
    SslClient();
    SslClient(const SslClient& orig);
    virtual ~SslClient();

private slots:
    void                onEncrypted();
    void                onReadyRead();
    
private:
    int                 _pSize;
};
}

#endif	/* SSLCLIENT_HPP */

