/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4013Component
*/

#ifndef COMPONENT4013_HPP_
    #define COMPONENT4013_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4013 : public vchips::AbstractComponent {
        public:
            Component4013();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4013_HPP_ */
