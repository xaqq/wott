#include <signal.h>
#include "Wott.hpp"
#include "WottApplication.hpp"
#include "Boot.hpp"
#include "sigDaemon.hpp"

int main(int ac, char **av)
{
    WottApplication app(ac, av);
    Boot *boot;
    SigDaemon    sigDaemons;

    signal(SIGINT, &SigDaemon::intSignalHandler);
    boot = new Boot;
    QTimer::singleShot(0, boot, SLOT(startInit()));

    return app.exec();
}
