/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentFalse.hpp"

vchips::ComponentFalse::ComponentFalse()
{
    this->setName(std::string("false"));
}

vchips::Tristate vchips::ComponentFalse::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr)
        *pins.at(1) = vchips::Tristate::FALSE;
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentFalse::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentFalse>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
