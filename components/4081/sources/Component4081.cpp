/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4081Component
*/

#include "Utils.hpp"
#include "Component4081.hpp"
#include "ComponentFactory.hpp"

vchips::Component4081::Component4081()
{
    this->setName(std::string("4081"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4081::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4081>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(14);
    auto and_1 = factory->createComponent("and", "");
    auto and_2 = factory->createComponent("and", "");
    auto and_3 = factory->createComponent("and", "");
    auto and_4 = factory->createComponent("and", "");
    (*component).setLink(1, *and_1, 1);
    (*component).setLink(2, *and_1, 2);
    (*component).setLink(3, *and_1, 3);
    (*component).setLink(5, *and_2, 1);
    (*component).setLink(6, *and_2, 2);
    (*component).setLink(4, *and_2, 3);
    (*component).setLink(8, *and_3, 1);
    (*component).setLink(9, *and_3, 2);
    (*component).setLink(10, *and_3, 3);
    (*component).setLink(12, *and_4, 1);
    (*component).setLink(13, *and_4, 2);
    (*component).setLink(11, *and_4, 3);
    component.get()->gatesToUpdate.push_back(std::move(and_1));
    component.get()->gatesToUpdate.push_back(std::move(and_2));
    component.get()->gatesToUpdate.push_back(std::move(and_3));
    component.get()->gatesToUpdate.push_back(std::move(and_4));
    return component;
}
