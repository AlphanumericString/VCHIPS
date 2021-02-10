/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#ifndef COMPONENT4071_HPP_
    #define COMPONENT4071_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4071 : public vchips::AbstractComponent {
        public:
            Component4071();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4071_HPP_ */
