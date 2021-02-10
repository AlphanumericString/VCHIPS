/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentTrue.hpp"

vchips::ComponentTrue::ComponentTrue()
{
    this->setName(std::string("true"));
}

vchips::Tristate vchips::ComponentTrue::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr)
        *pins.at(1) = vchips::Tristate::TRUE;
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentTrue::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentTrue>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
