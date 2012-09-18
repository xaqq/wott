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

private:
    /**
     * This function opens the connection to the database and initializes
     * its member _db.
     * @return isOk
     */
    bool                openConnection();

    /**
     * \brief The connection object
     */
    QSqlDatabase        _db;

private slots:
    void                init();
};
}

#endif	/* SQL_MANAGER_HPP */

