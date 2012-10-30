/*
 * File:   Manager.hpp
 * Author: xaqq
 *
 * Created on September 18, 2012, 2:19 AM
 */

#ifndef NETWORK_MANAGER_HPP
#define	NETWORK_MANAGER_HPP

#include "Wott.hpp"
#include "Network/SslServer.hpp"
#include <QList>
#include "Network/SslClient.hpp"
#include "Network/Client.hpp"

namespace Network
{

/**
 * \brief Network manager class. 
 * 
 * This class is the network manager. It lives in Network::_thread thread.
 * It owns a SslServer object. It also manages a list of SslClient and TcpClient
 * objects.
 */
class Manager : public QObject
{
    Q_OBJECT
public:
    Manager();
    Manager(const Manager& orig);
    virtual ~Manager();
    
    Client      *clientFromSsl(const SslClient *);

public slots:
    /**
     * Called when the whole module must shut down. This slot is triggered
     * when the program receives SIGINT for example.
     */
    void shutdownModule();

    /**
     * Init method, it is invoked by the Boot class.
     * The success bool is set to true or false so the calling
     * thread (ie the boot process) can know wether it worked or not.
     *
     * This is called with a BlockQueuedConnection
     * @param success reference on a bool.
     */
    void init(bool &success);

    /**
     * Method called when a new ssl connection has been successfully
     * established with the server.
     * You can get the connection using _sslSrv->nextPendingConnection();
     * It will create a new Network::Client instance.
     */
    void onNewSslClient();


private:
    SslServer           *_sslSrv;
    QList<Client *>     _clients;
    
};
}

#endif	/* Network_MANAGER_HPP */


