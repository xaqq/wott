/* 
 * File:   Client.cpp
 * Author: xaqq
 * 
 * Created on October 4, 2012, 1:25 PM
 */

#include "Network/Client.hpp"

Network::Client::Client() : QObject(0),
        _ssl(0), _id(0)
{
}

Network::Client::Client(const Client& orig) : QObject(0)
{
}

Network::Client::~Client()
{
}

void Network::Client::setSslClient(SslClient* s)
{
    _ssl = s;
}

const Network::SslClient *Network::Client::sslClient() const
{
    return _ssl;
}

void Network::Client::setToken(int t)
{
    _token = t;
}

int Network::Client::getToken() const
{
    return _token;
}