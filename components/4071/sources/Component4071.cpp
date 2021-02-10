/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "Component4071.hpp"
#include "ComponentFactory.hpp"

vchips::Component4071::Component4071()
{
    this->setName(std::string("4071"));
}

std::unique_ptr<vchips::IComponent> vchips::Component4071::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::Component4071>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(14);
    auto or_1 = factory->createComponent("or", "");
    auto or_2 = factory->createComponent("or", "");
    auto or_3 = factory->createComponent("or", "");
    auto or_4 = factory->createComponent("or", "");
    (*component).setLink(1, *or_1, 1);
    (*component).setLink(2, *or_1, 2);
    (*component).setLink(3, *or_1, 3);
    (*component).setLink(5, *or_2, 1);
    (*component).setLink(6, *or_2, 2);
    (*component).setLink(4, *or_2, 3);
    (*component).setLink(8, *or_3, 1);
    (*component).setLink(9, *or_3, 2);
    (*component).setLink(10, *or_3, 3);
    (*component).setLink(12, *or_4, 1);
    (*component).setLink(13, *or_4, 2);
    (*component).setLink(11, *or_4, 3);
    component.get()->gatesToUpdate.push_back(std::move(or_1));
    component.get()->gatesToUpdate.push_back(std::move(or_2));
    component.get()->gatesToUpdate.push_back(std::move(or_3));
    component.get()->gatesToUpdate.push_back(std::move(or_4));
    return component;
}
