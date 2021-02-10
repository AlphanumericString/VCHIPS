/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_

#include <memory>
#include <cstdlib>
#include "Tristate.hpp"

namespace vchips {
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual vchips::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, vchips::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::unique_ptr<vchips::IComponent> clone(const std::string &) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
