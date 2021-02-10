/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4514Component
*/

#include "Utils.hpp"
#include "Component4514.hpp"
#include "ComponentFactory.hpp"

vchips::Component4514::Component4514()
{
    this->setName(std::string("4514"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4514::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4514>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(24);
    auto latch = factory->createComponent("4_bits_latch", "");
    auto decoder = factory->createComponent("4_to_16_decoder", "");
    (*component).setLink(1, *latch, 5);
    (*component).setLink(2, *latch, 1);
    (*component).setLink(3, *latch, 2);
    (*component).setLink(21, *latch, 3);
    (*component).setLink(22, *latch, 4);
    (*latch).setLink(6, *decoder, 1);
    (*latch).setLink(7, *decoder, 2);
    (*latch).setLink(8, *decoder, 3);
    (*latch).setLink(9, *decoder, 4);
    (*latch).setLink(10, *decoder, 5);
    (*latch).setLink(11, *decoder, 6);
    (*latch).setLink(12, *decoder, 7);
    (*latch).setLink(13, *decoder, 8);
    (*component).setLink(23, *decoder, 9);
    (*decoder).setLink(10, *component, 11);
    (*decoder).setLink(11, *component, 10);
    (*decoder).setLink(12, *component, 9);
    (*decoder).setLink(13, *component, 8);
    (*decoder).setLink(14, *component, 7);
    (*decoder).setLink(15, *component, 6);
    (*decoder).setLink(16, *component, 5);
    (*decoder).setLink(17, *component, 4);
    (*decoder).setLink(18, *component, 18);
    (*decoder).setLink(19, *component, 17);
    (*decoder).setLink(20, *component, 20);
    (*decoder).setLink(21, *component, 19);
    (*decoder).setLink(22, *component, 14);
    (*decoder).setLink(23, *component, 13);
    (*decoder).setLink(24, *component, 16);
    (*decoder).setLink(25, *component, 15);
    component.get()->gatesToUpdate.push_back(std::move(latch));
    component.get()->gatesToUpdate.push_back(std::move(decoder));
    return component;
}
