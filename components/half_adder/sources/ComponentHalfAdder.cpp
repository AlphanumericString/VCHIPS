/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** HalfAdderComponent
*/

#include "Utils.hpp"
#include "ComponentHalfAdder.hpp"
#include "ComponentFactory.hpp"

vchips::ComponentHalfAdder::ComponentHalfAdder()
{
    this->setName(std::string("half_adder"));
}

std::unique_ptr<vchips::IComponent> vchips::ComponentHalfAdder::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentHalfAdder>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(5);
    auto xor_1 = factory->createComponent("xor", "");
    auto and_1 = factory->createComponent("and", "");
    (*component).setLink(1, *xor_1, 1);
    (*component).setLink(1, *and_1, 1);
    (*component).setLink(2, *xor_1, 2);
    (*component).setLink(2, *and_1, 2);
    (*component).setLink(3, *xor_1, 3);
    (*component).setLink(4, *and_1, 3);
    component.get()->gatesToUpdate.push_back(std::move(xor_1));
    component.get()->gatesToUpdate.push_back(std::move(and_1));
    return component;
}
