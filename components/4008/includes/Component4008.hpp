/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4008Component
*/

#ifndef COMPONENT4008_HPP_
    #define COMPONENT4008_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4008 : public vchips::AbstractComponent {
        public:
            Component4008();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4008_HPP_ */
