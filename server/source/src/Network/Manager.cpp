/*
 * File:   Manager.cpp
 * Author: xaqq
 *
 * Created on September 18, 2012, 2:19 AM
 */

#include "Network/Manager.hpp"
#include "Log.hpp"
#include "Boot.hpp"

Network::Manager::Manager()
{
}

Network::Manager::Manager(const Network::Manager&) : QObject(0)
{
}

Network::Manager::~Manager()
{
}

void Network::Manager::init(bool &success)
{
    success = false;
}

void Network::Manager::shutdownModule()
{
    Log::info("Network module shutting down...");
}
