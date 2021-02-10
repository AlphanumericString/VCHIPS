/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4011Component
*/

#include "Utils.hpp"
#include "Component4011.hpp"
#include "ComponentFactory.hpp"

vchips::Component4011::Component4011()
{
    this->setName(std::string("4011"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4011::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4011>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(14);
    auto nand_1 = factory->createComponent("nand", "");
    auto nand_2 = factory->createComponent("nand", "");
    auto nand_3 = factory->createComponent("nand", "");
    auto nand_4 = factory->createComponent("nand", "");
    (*component).setLink(1, *nand_1, 1);
    (*component).setLink(2, *nand_1, 2);
    (*component).setLink(3, *nand_1, 3);
    (*component).setLink(5, *nand_2, 1);
    (*component).setLink(6, *nand_2, 2);
    (*component).setLink(4, *nand_2, 3);
    (*component).setLink(8, *nand_3, 1);
    (*component).setLink(9, *nand_3, 2);
    (*component).setLink(10, *nand_3, 3);
    (*component).setLink(12, *nand_4, 1);
    (*component).setLink(13, *nand_4, 2);
    (*component).setLink(11, *nand_4, 3);
    component.get()->gatesToUpdate.push_back(std::move(nand_1));
    component.get()->gatesToUpdate.push_back(std::move(nand_2));
    component.get()->gatesToUpdate.push_back(std::move(nand_3));
    component.get()->gatesToUpdate.push_back(std::move(nand_4));
    return component;
}
