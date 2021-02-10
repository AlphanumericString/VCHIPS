/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4001Component
*/

#include "Utils.hpp"
#include "Component4001.hpp"
#include "ComponentFactory.hpp"

vchips::Component4001::Component4001()
{
    this->setName(std::string("4001"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4001::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4001>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(14);
    auto nor_1 = factory->createComponent("nor", "");
    auto nor_2 = factory->createComponent("nor", "");
    auto nor_3 = factory->createComponent("nor", "");
    auto nor_4 = factory->createComponent("nor", "");
    (*component).setLink(1, *nor_1, 1);
    (*component).setLink(2, *nor_1, 2);
    (*component).setLink(3, *nor_1, 3);
    (*component).setLink(5, *nor_2, 1);
    (*component).setLink(6, *nor_2, 2);
    (*component).setLink(4, *nor_2, 3);
    (*component).setLink(8, *nor_3, 1);
    (*component).setLink(9, *nor_3, 2);
    (*component).setLink(10, *nor_3, 3);
    (*component).setLink(12, *nor_4, 1);
    (*component).setLink(13, *nor_4, 2);
    (*component).setLink(11, *nor_4, 3);
    component.get()->gatesToUpdate.push_back(std::move(nor_1));
    component.get()->gatesToUpdate.push_back(std::move(nor_2));
    component.get()->gatesToUpdate.push_back(std::move(nor_3));
    component.get()->gatesToUpdate.push_back(std::move(nor_4));
    return component;
}
