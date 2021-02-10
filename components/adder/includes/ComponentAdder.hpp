/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** AdderComponent
*/

#ifndef COMPONENTADDER_HPP_
    #define COMPONENTADDER_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentAdder : public vchips::AbstractComponent {
        public:
            ComponentAdder();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENTADDER_HPP_ */
