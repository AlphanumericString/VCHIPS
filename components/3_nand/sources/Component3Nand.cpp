/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 3NandComponent
*/

#include "Utils.hpp"
#include "Component3Nand.hpp"
#include "ComponentFactory.hpp"

vchips::Component3Nand::Component3Nand()
{
    this->setName(std::string("3_nand"));
}

std::unique_ptr<vchips::IComponent> vchips::Component3Nand::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component3Nand>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(5);
    auto and_1 = factory->createComponent("and", "");
    auto nand_1 = factory->createComponent("nand", "");
    (*component).setLink(1, *and_1, 1);
    (*component).setLink(2, *and_1, 2);
    (*component).setLink(3, *nand_1, 1);
    (*and_1).setLink(3, *nand_1, 2);
    (*nand_1).setLink(3, *component, 4);
    component.get()->gatesToUpdate.push_back(std::move(and_1));
    component.get()->gatesToUpdate.push_back(std::move(nand_1));
    return component;
}
