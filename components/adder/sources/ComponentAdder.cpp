/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** AdderComponent
*/

#include "Utils.hpp"
#include "ComponentAdder.hpp"
#include "ComponentFactory.hpp"

vchips::ComponentAdder::ComponentAdder()
{
    this->setName(std::string("adder"));
}

std::unique_ptr<vchips::IComponent> vchips::ComponentAdder::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentAdder>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
    component.get()->pins.resize(6);
    auto half_adder_1 = factory->createComponent("half_adder", "");
    auto half_adder_2 = factory->createComponent("half_adder", "");
    auto or_1 = factory->createComponent("or", "");
    (*component).setLink(1, *half_adder_1, 1);
    (*component).setLink(2, *half_adder_1, 2);
    (*component).setLink(3, *half_adder_2, 2);
    (*half_adder_1).setLink(3, *half_adder_2, 1);
    (*half_adder_2).setLink(3, *component, 4);
    (*half_adder_1).setLink(4, *or_1, 1);
    (*half_adder_2).setLink(4, *or_1, 2);
    (*or_1).setLink(3, *component, 5);
    component.get()->gatesToUpdate.push_back(std::move(half_adder_1));
    component.get()->gatesToUpdate.push_back(std::move(half_adder_2));
    component.get()->gatesToUpdate.push_back(std::move(or_1));
    return component;
}
