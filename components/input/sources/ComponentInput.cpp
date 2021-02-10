/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** ComponentInput implementation
*/

#include "Utils.hpp"
#include "ComponentInput.hpp"

vchips::ComponentInput::ComponentInput()
{
    this->setName(std::string("input"));
}

std::unique_ptr<vchips::IComponent> vchips::ComponentInput::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentInput>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}

void vchips::ComponentInput::setInput(vchips::Tristate value)
{
}
