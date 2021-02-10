/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** HalfAdderComponent
*/

#ifndef COMPONENTHALF_ADDER_HPP_
    #define COMPONENTHALF_ADDER_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentHalfAdder : public vchips::AbstractComponent {
        public:
            ComponentHalfAdder();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENTHALF_ADDER_HPP_ */
