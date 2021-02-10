/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentSRNORLatch.hpp"

vchips::ComponentSRNORLatch::ComponentSRNORLatch()
{
    this->setName(std::string("sr_nor_latch"));
}

vchips::Tristate vchips::ComponentSRNORLatch::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr && pins.at(4) != nullptr) {
        if (*pins.at(1) == vchips::Tristate::TRUE && *pins.at(2) == vchips::Tristate::TRUE) {
            *pins.at(3) = vchips::Tristate::UNDEFINED;
            *pins.at(4) = vchips::Tristate::UNDEFINED;
        } else if (*pins.at(1) == vchips::Tristate::TRUE && *pins.at(2) == vchips::Tristate::FALSE) {
            local = vchips::Tristate::TRUE;
            *pins.at(3) = local;
            *pins.at(4) = ~local;
        } else if (*pins.at(1) == vchips::Tristate::FALSE && *pins.at(2) == vchips::Tristate::TRUE) {
            local = vchips::Tristate::FALSE;
            *pins.at(3) = local;
            *pins.at(4) = ~local;
        } else {
            *pins.at(3) = local;
            *pins.at(4) = ~local;
        }
    }
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentSRNORLatch::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentSRNORLatch>(*this);
    (void) value;
    component.get()->pins.resize(5);
    component.get()->local = vchips::Tristate::TRUE;
    return component;
}
