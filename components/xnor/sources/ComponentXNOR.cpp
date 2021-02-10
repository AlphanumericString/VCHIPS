/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentXNOR.hpp"

vchips::ComponentXNOR::ComponentXNOR()
{
    this->setName(std::string("xnor"));
}

vchips::Tristate vchips::ComponentXNOR::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr)
        *pins.at(3) = ~(*pins.at(1) ^ *pins.at(2));
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentXNOR::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentXNOR>(*this);
    (void) value;
    component.get()->pins.resize(4);
    return component;
}
