/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** main
*/

#include "Application.hpp"
#include "Simulation.hpp"

int main(int ac, char *av[])
{
    vchips::Application app;
    app.setup(ac, av);
    app.run();
}
