/*
** EPSI PROJECT, 2020
** Application.cpp
** File description:
** Application
*/

#include "Exception.hpp"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "Application.hpp"
#include "Utils.hpp"

vchips::Application::Application()
    : factory(vchips::ComponentFactory())
    , pluginLoader(nwmqpa::PluginLoader())
    , simulation(Simulation())
    , isRunning(false)
{}

vchips::Application::~Application()
{
    pluginLoader.unloadPlugins();
}

void vchips::Application::setup(int ac, char *av[]) noexcept
{
    chdir(INSTALL_PATH_STR);
    vchips::debug << "Path is: " << INSTALL_PATH_STR << std::endl;
    pluginLoader.loadPlugins<vchips::ComponentFactory>(&factory, std::string("./components"));
    try {
        simulation.setup(ac, av);
    } catch (vchips::ArgsError const &error) {
        std::cerr << program_invocation_short_name << ": " << error.what() << std::endl;
        exit(84);
    }
}

void vchips::Application::run()
{
    vchips::debug << "Launching the application." << std::endl;
    for (const std::string &name : factory.getNames()) {
        vchips::debug << name << std::endl;
    }
    simulation.run();
}
