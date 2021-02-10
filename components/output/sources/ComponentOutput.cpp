/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** ComponentOutput implementation
*/

#include "Utils.hpp"
#include "ComponentOutput.hpp"

vchips::ComponentOutput::ComponentOutput()
{
    this->setName(std::string("output"));
}

vchips::Tristate vchips::ComponentOutput::compute(std::size_t pin)
{
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentOutput::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentOutput>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
