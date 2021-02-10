/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4008Component
*/

#include "Utils.hpp"
#include "Component4008.hpp"
#include "ComponentFactory.hpp"

vchips::Component4008::Component4008()
{
    this->setName(std::string("4008"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4008::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4008>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(16);
    auto adder_1 = factory->createComponent("adder", "");
    auto adder_2 = factory->createComponent("adder", "");
    auto adder_3 = factory->createComponent("adder", "");
    auto adder_4 = factory->createComponent("adder", "");
    (*component).setLink(7, *adder_1, 1);
    (*component).setLink(6, *adder_1, 2);
    (*component).setLink(9, *adder_1, 3);
    (*component).setLink(5, *adder_2, 1);
    (*component).setLink(4, *adder_2, 2);
    (*adder_1).setLink(5, *adder_2, 3);
    (*component).setLink(3, *adder_3, 1);
    (*component).setLink(2, *adder_3, 2);
    (*adder_2).setLink(5, *adder_3, 3);
    (*component).setLink(1, *adder_4, 1);
    (*component).setLink(15, *adder_4, 2);
    (*adder_3).setLink(5, *adder_4, 3);
    (*adder_1).setLink(4, *component, 10);
    (*adder_2).setLink(4, *component, 11);
    (*adder_3).setLink(4, *component, 12);
    (*adder_4).setLink(4, *component, 13);
    (*adder_4).setLink(5, *component, 14);
    component.get()->gatesToUpdate.push_back(std::move(adder_1));
    component.get()->gatesToUpdate.push_back(std::move(adder_2));
    component.get()->gatesToUpdate.push_back(std::move(adder_3));
    component.get()->gatesToUpdate.push_back(std::move(adder_4));
    return component;
}
