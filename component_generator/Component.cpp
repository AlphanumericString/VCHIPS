/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** {0}Component
*/

#include "Utils.hpp"
#include "Component{0}.hpp"
#include "ComponentFactory.hpp"

vchips::Component{0}::Component{0}()
{{
    this->setName(std::string("{2}"));
}}

std::unique_ptr<vchips::IComponent> vchips::Component{0}::clone(const std::string &value)
{{
    auto component = std::make_unique<vchips::Component{0}>(*this);
    auto factory = vchips::ComponentFactory::getFactory();
    (void) value;
{1}
    return component;
}}
