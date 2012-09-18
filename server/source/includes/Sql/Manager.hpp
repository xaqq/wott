/*
 * File:   Manager.hpp
 * Author: xaqq
 *
 * Created on September 18, 2012, 2:19 AM
 */

#ifndef SQL_MANAGER_HPP
#define	SQL_MANAGER_HPP

#include "Wott.hpp"
#include <QtSql/QtSql>

namespace Sql
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
private:
    /**
     * This function opens the connection to the database and initializes
     * its member _db.
     * @return isOk
     */
    bool openConnection();

    /**
     * \brief The connection object
     */
    QSqlDatabase _db;

};
}

#endif	/* SQL_MANAGER_HPP */

