/*
 * File:   Boot.hpp
 * Author: xaqq
 *
 * Created on September 8, 2012, 7:27 PM
 */

#ifndef BOOT_HPP
#define	BOOT_HPP

#include "Wott.hpp"
#include "QSharedPointer"

class Boot;
typedef QSharedPointer<Boot> BootPtr;

class Boot
{
public:
    virtual ~Boot();
    static BootPtr instance();
    bool        init();
    bool        unload();

private:
    Boot();
    Boot(const Boot& orig);

    static BootPtr _me;
};

#endif	/* BOOT_HPP */

