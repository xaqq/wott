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

namespace Network
{

class SslServer : public QTcpServer
{
    Q_OBJECT
public:
    SslServer();
    SslServer(const SslServer& orig);
    virtual ~SslServer();
private:

};
}
#endif	/* NETWORK_SSLSERVER_HPP */

