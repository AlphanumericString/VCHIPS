/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4071Component
*/

#ifndef COMPONENTSRNANDLatch_HPP_
    #define COMPONENTSRNANDLatch_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentSRNANDLatch : public vchips::AbstractComponent {
        public:
            ComponentSRNANDLatch();
            vchips::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<vchips::IComponent> clone(const std::string &);
        private:
            vchips::Tristate local;
    };
}

#endif /* !COMPONENT4071_HPP_ */
