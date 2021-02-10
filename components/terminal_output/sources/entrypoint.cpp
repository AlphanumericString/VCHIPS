/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** entrypoint
*/

#include "ComponentTerminalOutput.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(vchips::ComponentFactory *factory)
{
    factory->registerComponent(new vchips::ComponentTerminalOutput(), std::string("terminal_output"));
}
