/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4030Component
*/

#ifndef COMPONENT4030_HPP_
    #define COMPONENT4030_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4030 : public vchips::AbstractComponent {
        public:
            Component4030();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4030_HPP_ */
