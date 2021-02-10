/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** Tristate
*/

#ifndef TRISTATE_HPP_
    #define TRISTATE_HPP_

#include <iostream>
#include <vector>

namespace vchips {
    enum Tristate {
        UNDEFINED = (-true),
        FALSE = false,
        TRUE = true
    };
}

vchips::Tristate operator&(const vchips::Tristate &lho, const vchips::Tristate &rho);
vchips::Tristate operator|(const vchips::Tristate &lho, const vchips::Tristate &rho);
vchips::Tristate operator^(const vchips::Tristate &lho, const vchips::Tristate &rho);
vchips::Tristate operator~(const vchips::Tristate &lho);
std::ostream &operator<<(std::ostream &stream, const vchips::Tristate &rho);
std::ostream &operator<<(std::ostream &stream, const std::vector<vchips::Tristate *> &rho);


#endif /* !TRISTATE_HPP_ */
