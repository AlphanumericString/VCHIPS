/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4BitsLatchComponent
*/

#include "Utils.hpp"
#include "Component4BitsLatch.hpp"
#include "ComponentFactory.hpp"

vchips::Component4BitsLatch::Component4BitsLatch()
{
    this->setName(std::string("4_bits_latch"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4BitsLatch::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4BitsLatch>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(14);
    auto not_1 = factory->createComponent("not", "");
    auto not_2 = factory->createComponent("not", "");
    auto not_3 = factory->createComponent("not", "");
    auto not_4 = factory->createComponent("not", "");
    auto not_5 = factory->createComponent("not", "");
    auto nand_1 = factory->createComponent("nand", "");
    auto nand_2 = factory->createComponent("nand", "");
    auto nand_3 = factory->createComponent("nand", "");
    auto nand_4 = factory->createComponent("nand", "");
    auto nand_5 = factory->createComponent("nand", "");
    auto nand_6 = factory->createComponent("nand", "");
    auto nand_7 = factory->createComponent("nand", "");
    auto nand_8 = factory->createComponent("nand", "");
    auto latch_1 = factory->createComponent("sr_nand_latch", "");
    auto latch_2 = factory->createComponent("sr_nand_latch", "");
    auto latch_3 = factory->createComponent("sr_nand_latch", "");
    auto latch_4 = factory->createComponent("sr_nand_latch", "");
    (*component).setLink(1, *not_1, 1);
    (*component).setLink(2, *not_2, 1);
    (*component).setLink(3, *not_3, 1);
    (*component).setLink(4, *not_4, 1);
    (*component).setLink(5, *not_5, 1);
    (*not_5).setLink(2, *nand_1, 2);
    (*not_5).setLink(2, *nand_2, 2);
    (*not_5).setLink(2, *nand_3, 2);
    (*not_5).setLink(2, *nand_4, 2);
    (*not_5).setLink(2, *nand_5, 2);
    (*not_5).setLink(2, *nand_6, 2);
    (*not_5).setLink(2, *nand_7, 2);
    (*not_5).setLink(2, *nand_8, 2);
    (*not_1).setLink(2, *nand_1, 1);
    (*not_2).setLink(2, *nand_2, 1);
    (*not_3).setLink(2, *nand_3, 1);
    (*not_4).setLink(2, *nand_4, 1);
    (*nand_1).setLink(3, *nand_5, 1);
    (*nand_2).setLink(3, *nand_6, 1);
    (*nand_3).setLink(3, *nand_7, 1);
    (*nand_4).setLink(3, *nand_8, 1);
    (*nand_1).setLink(3, *latch_1, 1);
    (*nand_2).setLink(3, *latch_2, 1);
    (*nand_3).setLink(3, *latch_3, 1);
    (*nand_4).setLink(3, *latch_4, 1);
    (*nand_5).setLink(3, *latch_1, 2);
    (*nand_6).setLink(3, *latch_2, 2);
    (*nand_7).setLink(3, *latch_3, 2);
    (*nand_8).setLink(3, *latch_4, 2);
    (*latch_1).setLink(3, *component, 6);
    (*latch_1).setLink(4, *component, 7);
    (*latch_2).setLink(3, *component, 8);
    (*latch_2).setLink(4, *component, 9);
    (*latch_3).setLink(3, *component, 10);
    (*latch_3).setLink(4, *component, 11);
    (*latch_4).setLink(3, *component, 12);
    (*latch_4).setLink(4, *component, 13);
    component.get()->gatesToUpdate.push_back(std::move(not_1));
    component.get()->gatesToUpdate.push_back(std::move(not_2));
    component.get()->gatesToUpdate.push_back(std::move(not_3));
    component.get()->gatesToUpdate.push_back(std::move(not_4));
    component.get()->gatesToUpdate.push_back(std::move(not_5));
    component.get()->gatesToUpdate.push_back(std::move(nand_1));
    component.get()->gatesToUpdate.push_back(std::move(nand_2));
    component.get()->gatesToUpdate.push_back(std::move(nand_3));
    component.get()->gatesToUpdate.push_back(std::move(nand_4));
    component.get()->gatesToUpdate.push_back(std::move(nand_5));
    component.get()->gatesToUpdate.push_back(std::move(nand_6));
    component.get()->gatesToUpdate.push_back(std::move(nand_7));
    component.get()->gatesToUpdate.push_back(std::move(nand_8));
    component.get()->gatesToUpdate.push_back(std::move(latch_1));
    component.get()->gatesToUpdate.push_back(std::move(latch_2));
    component.get()->gatesToUpdate.push_back(std::move(latch_3));
    component.get()->gatesToUpdate.push_back(std::move(latch_4));
    return component;
}
