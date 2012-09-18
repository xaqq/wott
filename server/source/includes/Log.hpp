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
/**
 * \brief Log Namespace
 */
namespace Log
{
class Manager;

/**
 * The thread where the logger manager lives.
 */
extern QThread *_thread;
/**
 * The logger manager.
 */
extern Manager *_manager;

/**
 * \brief Log message with priority "debug"
 * This is done by calling logDebug on the manager
 * @param QString Message to be logged
 */
void debug(const QString &);

/**
 * \brief Log message with priority "info"
 * This is done by calling logInfo on the manager
 * @param QString Message to be logged
 */
void info(const QString &);

/**
 * \brief Log message with priority "warn"
 * This is done by calling logWarn on the manager
 * @param QString Message to be logged
 */
void warn(const QString &);

/**
 * \brief Log message with priority "error"
 * This is done by calling logError on the manager
 * @param QString Message to be logged
 */
void error(const QString &);

};

#endif	/* LOG_HPP */

