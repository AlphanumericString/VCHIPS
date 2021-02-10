/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentNOR.hpp"

vchips::ComponentNOR::ComponentNOR()
{
    this->setName(std::string("nor"));
}

vchips::Tristate vchips::ComponentNOR::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr)
        *pins.at(3) = ~(*pins.at(1) | *pins.at(2));
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentNOR::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentNOR>(*this);
    (void) value;
    component.get()->pins.assign(4, nullptr);
    return component;
}
