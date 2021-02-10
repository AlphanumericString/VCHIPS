/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4030Component
*/

#include "Utils.hpp"
#include "Component4030.hpp"
#include "ComponentFactory.hpp"

vchips::Component4030::Component4030()
{
    this->setName(std::string("4030"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4030::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4030>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(14);
    auto xor_1 = factory->createComponent("xor", "");
    auto xor_2 = factory->createComponent("xor", "");
    auto xor_3 = factory->createComponent("xor", "");
    auto xor_4 = factory->createComponent("xor", "");
    (*component).setLink(1, *xor_1, 1);
    (*component).setLink(2, *xor_1, 2);
    (*component).setLink(3, *xor_1, 3);
    (*component).setLink(5, *xor_2, 1);
    (*component).setLink(6, *xor_2, 2);
    (*component).setLink(4, *xor_2, 3);
    (*component).setLink(8, *xor_3, 1);
    (*component).setLink(9, *xor_3, 2);
    (*component).setLink(10, *xor_3, 3);
    (*component).setLink(12, *xor_4, 1);
    (*component).setLink(13, *xor_4, 2);
    (*component).setLink(11, *xor_4, 3);
    component.get()->gatesToUpdate.push_back(std::move(xor_1));
    component.get()->gatesToUpdate.push_back(std::move(xor_2));
    component.get()->gatesToUpdate.push_back(std::move(xor_3));
    component.get()->gatesToUpdate.push_back(std::move(xor_4));
    return component;
}
