/*
 * File:   Manager.hpp
 * Author: xaqq
 *
 * Created on September 18, 2012, 2:19 AM
 */

#ifndef SQL_MANAGER_HPP
#define	SQL_MANAGER_HPP

#include "Wott.hpp"

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

};
}

#endif	/* SQL_MANAGER_HPP */

