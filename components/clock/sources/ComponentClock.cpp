/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentClock.hpp"

vchips::ComponentClock::ComponentClock()
{
    this->setName(std::string("clock"));
}

vchips::Tristate vchips::ComponentClock::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr)
        *pins.at(1) = ~(*pins.at(1));
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentClock::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentClock>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
