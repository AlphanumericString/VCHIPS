/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#ifndef COMPONENTFalse_HPP_
    #define COMPONENTFalse_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentFalse : public vchips::AbstractComponent {
        public:
            ComponentFalse();
            vchips::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<vchips::IComponent> clone(const std::string &);
    };
}

#endif /* !COMPONENT4071_HPP_ */
