/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4514Component
*/

#ifndef COMPONENT4514_HPP_
    #define COMPONENT4514_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4514 : public vchips::AbstractComponent {
        public:
            Component4514();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4514_HPP_ */
