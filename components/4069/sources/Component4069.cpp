/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4069Component
*/

#include "Utils.hpp"
#include "Component4069.hpp"
#include "ComponentFactory.hpp"

vchips::Component4069::Component4069()
{
    this->setName(std::string("4069"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4069::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4069>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(14);
    auto not_1 = factory->createComponent("not", "");
    auto not_2 = factory->createComponent("not", "");
    auto not_3 = factory->createComponent("not", "");
    auto not_4 = factory->createComponent("not", "");
    auto not_5 = factory->createComponent("not", "");
    auto not_6 = factory->createComponent("not", "");
    (*component).setLink(1, *not_1, 1);
    (*component).setLink(2, *not_1, 2);
    (*component).setLink(3, *not_2, 1);
    (*component).setLink(4, *not_2, 2);
    (*component).setLink(5, *not_3, 1);
    (*component).setLink(6, *not_3, 2);
    (*component).setLink(13, *not_1, 1);
    (*component).setLink(12, *not_1, 2);
    (*component).setLink(11, *not_2, 1);
    (*component).setLink(10, *not_2, 2);
    (*component).setLink(9, *not_3, 1);
    (*component).setLink(8, *not_3, 2);
    component.get()->gatesToUpdate.push_back(std::move(not_1));
    component.get()->gatesToUpdate.push_back(std::move(not_2));
    component.get()->gatesToUpdate.push_back(std::move(not_3));
    component.get()->gatesToUpdate.push_back(std::move(not_4));
    component.get()->gatesToUpdate.push_back(std::move(not_5));
    component.get()->gatesToUpdate.push_back(std::move(not_6));
    return component;
}
