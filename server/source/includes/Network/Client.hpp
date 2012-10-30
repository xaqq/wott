/* 
 * File:   Client.hpp
 * Author: xaqq
 *
 * Created on October 4, 2012, 1:25 PM
 */

#ifndef NETWORK_CLIENT_HPP
#define	NETWORK_CLIENT_HPP

#include "Wott.hpp"
#include "Network/SslClient.hpp"

namespace Network
{

class Client : public QObject
{
    Q_OBJECT

public:
    Client();
    Client(const Client& orig);
    virtual ~Client();

    void setSslClient(SslClient *s);
    const SslClient *sslClient() const;

    int getToken() const;
    void setToken(int t);
    
private:
    int _id;
    int _token;
    SslClient *_ssl;

};
}
#endif	/* NETWORK_CLIENT_HPP */

