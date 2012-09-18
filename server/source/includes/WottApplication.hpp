/*
 * File:   WootApplication.hpp
 * Author: xaqq
 *
 * Created on September 17, 2012, 11:13 PM
 */

#ifndef WOTTAPPLICATION_HPP
#define	WOTTAPPLICATION_HPP

#include "Wott.hpp"

class WottApplication : public QCoreApplication
{
    Q_OBJECT;
public:

    WottApplication(int &c, char **v) : QCoreApplication(c, v)
    {
    }
    virtual ~WottApplication();
    bool notify(QObject *rec, QEvent *ev) override;

public slots:
    void shutdownServer();
};

#endif	/* WOOTAPPLICATION_HPP */

