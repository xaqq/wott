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

namespace Network
{

class Manager : public QObject
{
    Q_OBJECT
public:
    Manager();
    Manager(const Manager& orig);
    virtual ~Manager();

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

    void newSslClient();


private:
    SslServer *_sslSrv;

};
}

#endif	/* Network_MANAGER_HPP */


