/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** AbstractComponent
*/

#include <iostream>
#include "Utils.hpp"
#include "AbstractComponent.hpp"
#include "ComponentFactory.hpp"

vchips::AbstractComponent::~AbstractComponent()
{
}

vchips::AbstractComponent::AbstractComponent()
{
}

vchips::AbstractComponent::AbstractComponent(const AbstractComponent &component)
{
    this->name = component.name;
}

vchips::Tristate vchips::AbstractComponent::compute(std::size_t pin)
{
    for (auto &&gate : gatesToUpdate) {
        gate->compute();
    }
    return *pins.at(pin);
}

void vchips::AbstractComponent::setLink(std::size_t pin, vchips::IComponent &other, std::size_t otherPin)
{
    vchips::AbstractComponent &otherComponent = (static_cast<vchips::AbstractComponent &> (other));
    if (otherComponent.pins.at(otherPin) != nullptr && pins.at(pin) != nullptr) {
        otherComponent.recomputeGraph(otherComponent.pins.at(otherPin), pins.at(pin));
    }
    if (pins.at(pin) != nullptr) {
        otherComponent.pins.at(otherPin) = pins.at(pin);
        return;
    }
    if (otherComponent.pins.at(otherPin) != nullptr) {
        pins.at(pin) = otherComponent.pins.at(otherPin);
        return;
    }
    vchips::Tristate *tristate = new vchips::Tristate;
    *tristate = vchips::Tristate::FALSE;
    pins.at(pin) = tristate;
    otherComponent.pins.at(otherPin) = tristate;
    ComponentFactory::getFactory()->registerPin(tristate);
}

void vchips::AbstractComponent::setPinAt(std::size_t pin, vchips::Tristate value)
{
    *(pins.at(pin)) = value;
}

vchips::Tristate vchips::AbstractComponent::getOutput() const
{
    return *(pins.at(1));
}

void vchips::AbstractComponent::recomputeGraph(vchips::Tristate *oldPtr, vchips::Tristate *newPtr)
{
    for (std::size_t i = 0; i < pins.size(); i++) {
        if (pins.at(i) == oldPtr)
            pins.at(i) = newPtr;
    }
    for (auto &&gate : gatesToUpdate) {
        (static_cast<vchips::AbstractComponent *> (gate.get()))->recomputeGraph(oldPtr, newPtr);
    }
}

void vchips::AbstractComponent::setName(const std::string &name)
{
    this->name = name;
}

void vchips::AbstractComponent::dump() const
{
    std::cout << "Dump of component " << name << ":" << std::endl;
    for (auto &&gate : gatesToUpdate) {
        static_cast<vchips::AbstractComponent *>(gate.get())->dump();
    }
    std::cout << "Pins:" << std::endl;
    std::cout << pins << std::endl;
    std::cout << "End of dump of component " << name << std::endl;
}
