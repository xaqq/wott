/* 
 * File:   Network.hpp
 * Author: xaqq
 *
 * Created on October 2, 2012, 2:37 PM
 */

#ifndef NETWORK_HPP
#define	NETWORK_HPP

#include "Wott.hpp"

class QThread;
/**
 * \brief Network Namespace
 */
namespace Network
{
class Manager;

/**
 * The thread where the Network manager lives.
 */
extern QThread *_thread;
/**
 * The Network manager.
 */
extern Manager *_manager;
};

#include "Network/Manager.hpp"

#endif	/* NETWORK_HPP */

