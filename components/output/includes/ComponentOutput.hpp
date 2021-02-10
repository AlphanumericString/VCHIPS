/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** ComponentOutput header
*/

#ifndef COMPONENTOUTPUT_HPP_
    #define COMPONENTOUTPUT_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentOutput : public vchips::AbstractComponent {
        public:
            ComponentOutput();
            vchips::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<vchips::IComponent> clone(const std::string &);
    };
}

#endif /* !COMPONENTOUTPUT_HPP_ */
