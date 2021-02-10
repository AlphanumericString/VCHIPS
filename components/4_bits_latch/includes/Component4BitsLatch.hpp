/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4BitsLatchComponent
*/

#ifndef COMPONENT4_BITS_LATCH_HPP_
    #define COMPONENT4_BITS_LATCH_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4BitsLatch : public vchips::AbstractComponent {
        public:
            Component4BitsLatch();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4_BITS_LATCH_HPP_ */
