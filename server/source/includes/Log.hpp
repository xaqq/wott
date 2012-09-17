/*
 * File:   Log.hpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 10:20 PM
 */

#ifndef LOG_HPP
#define	LOG_HPP

#include "Wott.hpp"

class QThread;
namespace Log
{
class Manager;

extern QThread *_thread;
extern Manager *_manager;

void info(const QString &);
};

#endif	/* LOG_HPP */

