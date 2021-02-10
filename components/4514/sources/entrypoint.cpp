/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** entrypoint
*/

#include "Component4514.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(vchips::ComponentFactory *factory)
{
    factory->registerComponent(new vchips::Component4514(), std::string("4514"));
}
