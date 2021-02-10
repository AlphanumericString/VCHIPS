/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentNOT.hpp"

vchips::ComponentNOT::ComponentNOT()
{
    this->setName(std::string("not"));
}

vchips::Tristate vchips::ComponentNOT::compute(std::size_t pin)
{
    if (pins.at(2) != nullptr && pins.at(1) != nullptr)
        *pins.at(2) = ~(*pins.at(1));
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentNOT::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentNOT>(*this);
    (void) value;
    component.get()->pins.resize(3);
    return component;
}
