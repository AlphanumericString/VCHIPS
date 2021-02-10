/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#ifndef COMPONENTXOR_HPP_
    #define COMPONENTXOR_HPP_

#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentXOR : public vchips::AbstractComponent {
        public:
            ComponentXOR();
            vchips::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<vchips::IComponent> clone(const std::string &);
    };
}

#endif /* !COMPONENT4071_HPP_ */
