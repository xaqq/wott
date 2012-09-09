#include <QCoreApplication>
#include "Wott.hpp"
#include "Boot.hpp"

int main(int ac, char **av)
{
    QCoreApplication app(ac, av);
    BootPtr boot;

    boot = Boot::instance();
    if (!boot->init())
    {
        boot->unload();
        return -1;
    }
    return app.exec();
}
