/* 
 * File:   SslServer.cpp
 * Author: xaqq
 * 
 * Created on October 2, 2012, 3:13 PM
 */

#include "Network/SslServer.hpp"

Network::SslServer::SslServer() : QTcpServer(0)
{
}

Network::SslServer::SslServer(const SslServer& orig) : QTcpServer(0)
{
}

Network::SslServer::~SslServer()
{
}

