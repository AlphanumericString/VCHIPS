/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4011Component
*/

#ifndef COMPONENT4011_HPP_
    #define COMPONENT4011_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4011 : public vchips::AbstractComponent {
        public:
            Component4011();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4011_HPP_ */
