/*
 * File:   WootApplication.cpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:13 PM
 */

#include <QThread>
#include "WottApplication.hpp"
#include <iostream>

WottApplication::~WottApplication()
{
}

bool WottApplication::notify(QObject *rec, QEvent *ev)
{
    // cDebug() << "Called Application::notify()" << endl;
    try
    {
        return QCoreApplication::notify(rec, ev);
    }
    catch (char const *str)
    {
        std::cerr << "EXCEPTION: " << str << std::endl;
        return false;
    }
    catch (int i)
    {
        std::cout << "Notify in thread " << QThread::currentThread() << std::endl;
        std::cerr << "Int exception" << i << std::endl;
        return false;
    }
    catch (...)
    {
        std::cerr << "Unknown exception!" << std::endl;
        abort();
    }
}