/* 
 * File:   SslClient.cpp
 * Author: xaqq
 * 
 * Created on October 4, 2012, 2:04 PM
 */

#include "Network/SslClient.hpp"
#include "Log.hpp"


Network::SslClient::SslClient()
{
}


Network::SslClient::SslClient(const SslClient& orig)
{
}

Network::SslClient::~SslClient()
{
    Log::error("DELETING SSL CLIENT");
}

void Network::SslClient::onReadyRead()
{
    Log::debug("Socket read: " + QString(readAll().constData()));
}

void Network::SslClient::onEncrypted()
{
    connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}