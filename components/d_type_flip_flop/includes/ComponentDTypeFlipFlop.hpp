/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** DTypeFlipFlopComponent
*/

#ifndef COMPONENTD_TYPE_FLIP_FLOP_HPP_
    #define COMPONENTD_TYPE_FLIP_FLOP_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentDTypeFlipFlop : public vchips::AbstractComponent {
        public:
            ComponentDTypeFlipFlop();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENTD_TYPE_FLIP_FLOP_HPP_ */
