/*
** EPSI PROJECT, 2020
** Simulation.cpp
** File description:
** Simulation implementation
*/

#include "Exception.hpp"
#include "Simulation.hpp"
#include "Utils.hpp"
#include "AbstractComponent.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <csignal>
#include <unistd.h>

bool isLoop;

Simulation::Simulation()
    : _components(std::map<std::string, std::unique_ptr<vchips::IComponent>>())
    , _inputs(std::map<std::string, std::unique_ptr<vchips::IComponent>>())
    , _outputs(std::map<std::string, std::unique_ptr<vchips::IComponent>>())
    , _parser(Parser())
    , _isReady(false)
{}

vchips::IComponent *Simulation::getComponent(const std::string &name)
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _components[cursor].get();
    }
    for (auto i = _inputs.begin(); i != _inputs.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _inputs[cursor].get();
    }
    for (auto i = _outputs.begin(); i != _outputs.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _outputs[cursor].get();
    }
    return nullptr;
}

void Simulation::setupChipsets()
{
    auto chipsets = _parser.getChipsets();

    for (auto [type, name, param] : chipsets) {
        if (!type.compare("input"))
            _inputs[name] = std::move(vchips::ComponentFactory::getFactory()->createComponent(type, param));
        else if (!type.compare("output"))
            _outputs[name] = std::move(vchips::ComponentFactory::getFactory()->createComponent(type, param));
        else
            _components[name] = std::move(vchips::ComponentFactory::getFactory()->createComponent(type, param));
    }
}

void Simulation::setupLinks()
{
    auto links = _parser.getLinks();

    for (auto [c1, p1, c2, p2] : links) {
        getComponent(c1)->setLink(std::stoi(p1), *getComponent(c2), std::stoi(p2));
    }
}

void Simulation::setup(int ac, char *av[])
{
    std::regex reg("([a-zA-Z0-9_]+)=([01]?)");
    std::smatch match;
    std::string line;
    std::vector<std::string> tmp;

    if (ac < 2)
        throw vchips::FileError("nts file not specified.");
    _parser.parseFile(av[1]);
    setupChipsets();
    setupLinks();
    if ((ac != (2 + _parser.countComponent("input"))))
        throw vchips::ArgsError("all inputs values must be specified (no more, no less).");
    for (int i = 2; i != ac; i++) {
        line.assign(av[i]);
        if (std::regex_match(line, match, reg)) {
            try {
                isValidArgument(tmp, match[1]);
            } catch (vchips::SyntaxError const &error) {
                std::cerr << program_invocation_short_name << ": " << error.what() << std::endl;
                std::exit(84);
            }
            if (!std::string(match[2]).empty()) {
                setInput(match[1], match[2]);
                tmp.push_back(match[2]);
            } else {
                throw vchips::ArgsError(line + ": invalid option.");
            }
        } else
            throw vchips::ArgsError(line + ": invalid option.");
    }
    _isReady = true;
}

void Simulation::actionChoice(const std::string &line, std::smatch match)
{
    if (!line.compare("dump"))
        dump();
    else if (!line.compare("exit"))
        exit();
    else if (!line.compare("simulate"))
        simulate();
    else if (!line.compare("loop"))
        loop();
    else if (!line.compare("display"))
        display();
    else
        setInput(match[1], match[2]);
}

void Simulation::run()
{
    std::regex reg("(?:([a-zA-Z0-9_]+)=([01]))|(dump|exit|simulate|loop|display)");
    std::smatch match;
    std::string line;

    vchips::debug << "Starting simulation..." << std::endl;
    simulate();
    display();
    while (_isReady) {
        std::cout << "> ";
        if ((line = getUserInput()).empty())
            return exit();
        if (std::regex_match(line, match, reg))
            actionChoice(match[0], match);
        else
            std::cerr << program_invocation_short_name << ": " << line << ": invalid option." << std::endl;
    }
}

void Simulation::exit()
{
    for (auto i = _inputs.begin(); i != _inputs.end();)
        i = _inputs.erase(i);
    for (auto i = _outputs.begin(); i != _outputs.end();)
        i = _outputs.erase(i);
    for (auto i = _components.begin(); i != _components.end();)
        i = _components.erase(i);
    _isReady = false;
}

void Simulation::display()
{
    for (auto i = _outputs.begin(); i != _outputs.end(); i++) {
        auto cursor = i->first;
        std::cout << cursor << "=" << static_cast<vchips::AbstractComponent *>(_outputs[cursor].get())->getOutput() << std::endl;
    }
}

void Simulation::simulate()
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        _components[cursor]->compute();
    }
}

void loopStop(int sig)
{
    (void) sig;
    isLoop = false;
}

void Simulation::loop()
{
    struct sigaction handler;

    handler.sa_handler = loopStop;
    sigemptyset(&handler.sa_mask);
    handler.sa_flags = 0;
    sigaction(SIGINT, &handler, NULL);
    isLoop = true;
    while (isLoop)
        simulate();
}

void Simulation::dump()
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        _components[cursor]->dump();
    }
}

void Simulation::setInput(const std::string &name, const std::string &value)
{
    if (getComponent(name) == nullptr) {
        std::cerr << program_invocation_short_name << ": can\'t find \'" << name << "\'." << std::endl;
        return;
    }
    if (!value.compare("0"))
        static_cast<vchips::AbstractComponent *>(getComponent(name))->setPinAt(1, vchips::Tristate::FALSE);
    else
        static_cast<vchips::AbstractComponent *>(getComponent(name))->setPinAt(1, vchips::Tristate::TRUE);
}

std::string Simulation::getUserInput()
{
    std::string line;

    std::getline(std::cin, line);
    return line;
}

void Simulation::isValidArgument(std::vector<std::string> &list, const std::string &name)
{
    auto chipsets = _parser.getChipsets();
    bool inChips = false;

    for (std::string elem : list) {
        if (!name.compare(elem))
            throw vchips::SyntaxError("\'" + name + "\' value is set multiple times.");
    }
    for (auto [cType, cName, cParam] : chipsets) {
        if (!name.compare(cName)) {
            inChips = true;
            break;
        }
    }
    if (!inChips)
        throw vchips::SyntaxError("can\'t find \'" + name + "\'.");
}
