/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentTerminalOutput.hpp"

vchips::ComponentTerminalOutput::ComponentTerminalOutput()
{
    this->setName(std::string("terminal_output"));
}

vchips::Tristate vchips::ComponentTerminalOutput::compute(std::size_t pin)
{
    char c = 0;
    for (std::size_t i = 1; i < 9; i++) {
        if (pins.at(i) != nullptr) {
            c += (*pins.at(i) == vchips::Tristate::TRUE ? 1 : 0) << (i - 1);
        }
    }
    if (pins.at(9) != nullptr && *pins.at(9) == vchips::Tristate::TRUE)
        std::cout << c << std::flush;
    return *pins.at(pin);
}

std::unique_ptr<vchips::IComponent> vchips::ComponentTerminalOutput::clone(const std::string &value)
{
    auto component = std::make_unique<vchips::ComponentTerminalOutput>(*this);
    (void) value;
    component.get()->pins.resize(10);
    return component;
}
