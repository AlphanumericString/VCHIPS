/*
** EPSI PROJECT, 2020
** cpp_rush3_2020
** File description:
** ModuleFactory
*/

#include <iostream>
#include "ComponentFactory.hpp"
#include "Utils.hpp"

vchips::ComponentFactory *vchips::ComponentFactory::singleton = nullptr;

vchips::ComponentFactory::ComponentFactory()
: pins(),
  instances()
{
    if (singleton == nullptr)
        singleton = this;
}

vchips::ComponentFactory::~ComponentFactory()
{
    for (; pins.size() != 0; ) {
        delete pins.back();
        pins.pop_back();
    }
}

bool vchips::ComponentFactory::registerComponent(vchips::IComponent *component, const std::string &name)
{
    if (name.size() == 0) {
        std::cerr << "Cannot register component: No name given" << std::endl;
        return false;
    }
    if (component == nullptr) {
        std::cerr << "Cannot register component " << name << ": pointer is null" << std::endl;
        return false;
    }
    for (auto &temp : this->instances) {
        if (temp.first.compare(name) == 0) {
            std::cerr << "Cannot register component: " << name << ", name already registered" << std::endl;
            return false;
        }
    }
    this->instances[name] = component;
    vchips::debug << "Component " << name << " registered." << std::endl;
    return true;
}

void vchips::ComponentFactory::registerPin(vchips::Tristate *pin)
{
    pins.push_back(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentFactory::createComponent(const std::string &name, const std::string &value) const
{
    try {
        return this->instances.at(name)->clone(value);
    } catch (const std::out_of_range &e) {
        throw std::runtime_error(std::string("No such component: ") + name);
    }
}

std::vector<std::string> vchips::ComponentFactory::getNames() const
{
    std::vector<std::string> names;
    for (auto &temp : this->instances) {
        names.push_back(temp.first);
    }
    return (names);
}

vchips::ComponentFactory *vchips::ComponentFactory::getFactory()
{
    return ComponentFactory::singleton;
}
