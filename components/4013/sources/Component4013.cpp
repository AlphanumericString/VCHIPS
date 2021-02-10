/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4013Component
*/

#include "Utils.hpp"
#include "Component4013.hpp"
#include "ComponentFactory.hpp"

vchips::Component4013::Component4013()
{
    this->setName(std::string("4013"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4013::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4013>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(14);
    auto latch_1 = factory->createComponent("d_type_flip_flop", "");
    auto latch_2 = factory->createComponent("d_type_flip_flop", "");
    (*component).setLink(3, *latch_1, 1);
    (*component).setLink(5, *latch_1, 2);
    (*component).setLink(6, *latch_1, 3);
    (*component).setLink(4, *latch_1, 4);
    (*latch_1).setLink(5, *component, 1);
    (*latch_1).setLink(6, *component, 2);
    (*component).setLink(11, *latch_2, 1);
    (*component).setLink(9, *latch_2, 2);
    (*component).setLink(8, *latch_2, 3);
    (*component).setLink(10, *latch_2, 4);
    (*latch_2).setLink(5, *component, 13);
    (*latch_2).setLink(6, *component, 12);
    component.get()->gatesToUpdate.push_back(std::move(latch_1));
    component.get()->gatesToUpdate.push_back(std::move(latch_2));
    return component;
}
