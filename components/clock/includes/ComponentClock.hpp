/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#ifndef COMPONENTClock_HPP_
    #define COMPONENTClock_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentClock : public vchips::AbstractComponent {
        public:
            ComponentClock();
            vchips::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<vchips::IComponent> clone(const std::string &);
    };
}

#endif /* !COMPONENT4071_HPP_ */
