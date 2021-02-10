/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentXOR.hpp"

vchips::ComponentXOR::ComponentXOR()
{
    this->setName(std::string("xor"));
}

vchips::Tristate vchips::ComponentXOR::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr)
        *pins.at(3) = *pins.at(1) ^ *pins.at(2);
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentXOR::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentXOR>(*this);
    (void) value;
    component.get()->pins.resize(4);
    return component;
}
