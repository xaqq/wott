/*
 * File:   Manager.cpp
 * Author: xaqq
 *
 * Created on September 18, 2012, 2:19 AM
 */

#include "Sql/Manager.hpp"
#include "Log.hpp"
#include "Boot.hpp"
#include <QTimer>

Sql::Manager::Manager()
{
}

Sql::Manager::Manager(const Sql::Manager&) : QObject(0)
{
}

Sql::Manager::~Manager()
{
}

bool Sql::Manager::openConnection()
{
    _db = QSqlDatabase::addDatabase("QMYSQL");
    _db.setHostName("localhost");
    _db.setDatabaseName("test");
    _db.setUserName("test");
    _db.setPassword("test");

    bool ok = _db.open();
    if (!ok)
    {
        Log::error("Sql Error" + _db.lastError().text());
        return ok;
    }
    Log::info("Sql Connection OK");

    const QStringList &t = _db.tables();
    for (QStringList::const_iterator it = t.constBegin(); it != t.constEnd();
            it++)
        Log::info(*it);

    return ok;
}

void Sql::Manager::init(bool &success)
{
    success = openConnection();
}

void Sql::Manager::shutdownModule()
{
    Log::info("Sql module shutting down...");
    _db.close();
}