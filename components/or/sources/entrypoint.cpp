/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** entrypoint
*/

#include "ComponentOR.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(vchips::ComponentFactory *factory)
{
    factory->registerComponent(new vchips::ComponentOR(), std::string("or"));
}
