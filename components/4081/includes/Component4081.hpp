/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4081Component
*/

#ifndef COMPONENT4081_HPP_
    #define COMPONENT4081_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4081 : public vchips::AbstractComponent {
        public:
            Component4081();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4081_HPP_ */
