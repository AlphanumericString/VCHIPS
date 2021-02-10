/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** DTypeFlipFlopComponent
*/

#include "Utils.hpp"
#include "ComponentDTypeFlipFlop.hpp"
#include "ComponentFactory.hpp"

vchips::ComponentDTypeFlipFlop::ComponentDTypeFlipFlop()
{
    this->setName(std::string("d_type_flip_flop"));
}

std::unique_ptr<vchips::IComponent> vchips::ComponentDTypeFlipFlop::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentDTypeFlipFlop>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(7);
    auto not_1 = factory->createComponent("not", "");
    auto nand_1 = factory->createComponent("nand", "");
    auto nand_2 = factory->createComponent("nand", "");
    auto or_1 = factory->createComponent("xor", "");
    auto or_2 = factory->createComponent("xor", "");
    auto sr_nand_latch_1 = factory->createComponent("sr_nand_latch", "");
    (*component).setLink(1, *nand_1, 1);
    (*component).setLink(1, *nand_2, 1);
    (*component).setLink(2, *nand_1, 2);
    (*component).setLink(2, *not_1, 1);
    (*not_1).setLink(2, *nand_2, 2);
    (*component).setLink(3, *or_1, 1);
    (*nand_1).setLink(3, *or_1, 2);
    (*or_1).setLink(3, *sr_nand_latch_1, 1);
    (*component).setLink(4, *or_2, 1);
    (*nand_2).setLink(3, *or_2, 2);
    (*or_2).setLink(3, *sr_nand_latch_1, 2);
    (*sr_nand_latch_1).setLink(3, *component, 5);
    (*sr_nand_latch_1).setLink(4, *component, 6);
    component.get()->gatesToUpdate.push_back(std::move(not_1));
    component.get()->gatesToUpdate.push_back(std::move(nand_1));
    component.get()->gatesToUpdate.push_back(std::move(nand_2));
    component.get()->gatesToUpdate.push_back(std::move(or_1));
    component.get()->gatesToUpdate.push_back(std::move(or_2));
    component.get()->gatesToUpdate.push_back(std::move(sr_nand_latch_1));
    return component;
}
