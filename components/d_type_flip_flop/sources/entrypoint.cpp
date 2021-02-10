/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** entrypoint
*/

#include "ComponentDTypeFlipFlop.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(vchips::ComponentFactory *factory)
{
    factory->registerComponent(new vchips::ComponentDTypeFlipFlop(), std::string("d_type_flip_flop"));
}
