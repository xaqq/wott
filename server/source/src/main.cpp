#include "Wott.hpp"
#include "WottApplication.hpp"
#include "Boot.hpp"

int main(int ac, char **av)
{
    WottApplication app(ac, av);
    Boot *boot;

    boot = new Boot;
    QTimer::singleShot(0, boot, SLOT(startInit()));

    return app.exec();
}
