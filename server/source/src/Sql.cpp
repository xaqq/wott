/*
 * File:   Sql.cpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 10:32 PM
 */

#include "Sql.hpp"
#include "Sql/Manager.hpp"

QThread *Sql::_thread = 0;
Sql::Manager *Sql::_manager = 0;
