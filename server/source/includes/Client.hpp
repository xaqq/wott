/* 
 * File:   Client.hpp
 * Author: xaqq
 *
 * Created on October 5, 2012, 9:05 AM
 */

#ifndef CLIENT_HPP
#define	CLIENT_HPP

#include "Wott.hpp"
#include "Network/Client.hpp"

class Client : public QObject
{
    Q_OBJECT
public:
    Client();
    Client(const Client& orig);
    virtual ~Client();
private:
    Network::Client     *_net;

};

#endif	/* CLIENT_HPP */

