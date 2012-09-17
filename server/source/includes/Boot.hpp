/*
 * File:   Boot.hpp
 * Author: xaqq
 *
 * Created on September 8, 2012, 7:27 PM
 */

#pragma once

#include "Wott.hpp"

class Boot : public QObject
{
    Q_OBJECT
public:

public slots:
    void startInit();
    bool initLog();
};
