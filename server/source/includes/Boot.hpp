/*
 * File:   Boot.hpp
 * Author: xaqq
 *
 * Created on September 8, 2012, 7:27 PM
 */

#pragma once

#include "Wott.hpp"

/**
 * \brief Class to handle server startup process.
 *
 * The boot class is used in main() to prepare the server.
 * It is responsible for creating thread and starting them.
 *
 */
class Boot : public QObject
{
    Q_OBJECT
public:

public slots:
    void startInit();

    /**
     * \brief Initialize the log module.
     *
     * This module initialization is rather easy since there is no reason
     * for it to fail.
     * @return bool always true
     */
    bool initLog();

    /**
     * \brief Initialize the Sql module.
     * 
     * Create a SQL connection to the database.
     * See SQL module documentation for more infos
     * @return bool success
     */
    bool initSql();

    /**
     * \brief Initialize the Network module.
     * 
     * Set up a TCP server and a SSL Server.
     * See Network module documentation for more infos
     * @return bool success
     */
    bool initNetwork();
};
