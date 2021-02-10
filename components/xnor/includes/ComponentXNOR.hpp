/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#ifndef COMPONENTXNOR_HPP_
    #define COMPONENTXNOR_HPP_

#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentXNOR : public vchips::AbstractComponent {
        public:
            ComponentXNOR();
            vchips::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<vchips::IComponent> clone(const std::string &);
    };
}

#endif /* !COMPONENT4071_HPP_ */
