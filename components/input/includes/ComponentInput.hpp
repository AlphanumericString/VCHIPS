/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** ComponentInput header
*/

#ifndef COMPONENTINPUT_HPP_
    #define COMPONENTINPUT_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentInput : public vchips::AbstractComponent {
        public:
            ComponentInput();
            std::unique_ptr<vchips::IComponent> clone(const std::string &);
            void setInput(vchips::Tristate value);
    };
}

#endif /* !COMPONENTINPUT_HPP_ */
