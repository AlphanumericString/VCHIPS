/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4001Component
*/

#ifndef COMPONENT4001_HPP_
    #define COMPONENT4001_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4001 : public vchips::AbstractComponent {
        public:
            Component4001();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4001_HPP_ */
