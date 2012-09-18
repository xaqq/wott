/*
 * File:   Sql.hpp
 * Author: xaqq
 *
 * Created on September 18, 2012, 2:20 AM
 */

#ifndef SQL_HPP
#define	SQL_HPP

#include "Wott.hpp"

class QThread;
/**
 * \brief Sql Namespace
 */
namespace Sql
{
class Manager;

/**
 * The thread where the sql manager lives.
 */
extern QThread *_thread;
/**
 * The Sql manager.
 */
extern Manager *_manager;
};

#include "Sql/Manager.hpp"

#endif	/* SQL_HPP */

