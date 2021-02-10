/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#ifndef COMPONENTNOR_HPP_
    #define COMPONENTNOR_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentNOR : public vchips::AbstractComponent {
        public:
            ComponentNOR();
            vchips::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4071_HPP_ */
