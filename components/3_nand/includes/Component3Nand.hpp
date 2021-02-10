/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 3NandComponent
*/

#ifndef COMPONENT3_NAND_HPP_
    #define COMPONENT3_NAND_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component3Nand : public vchips::AbstractComponent {
        public:
            Component3Nand();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT3_NAND_HPP_ */
