/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** entrypoint
*/

#include "ComponentXNOR.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(vchips::ComponentFactory *factory)
{
    factory->registerComponent(new vchips::ComponentXNOR(), std::string("xnor"));
}
