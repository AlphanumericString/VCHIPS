/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** Tristate
*/

#include "Tristate.hpp"

vchips::Tristate operator&(const vchips::Tristate &lho, const vchips::Tristate &rho)
{
    if (lho == vchips::Tristate::UNDEFINED || rho == vchips::Tristate::UNDEFINED)
        return vchips::Tristate::UNDEFINED;
    if (lho == rho)
        return rho;
    return vchips::Tristate::FALSE;
}

vchips::Tristate operator|(const vchips::Tristate &lho, const vchips::Tristate &rho)
{
    if (lho == vchips::Tristate::UNDEFINED || rho == vchips::Tristate::UNDEFINED)
        return vchips::Tristate::UNDEFINED;
    if (lho == vchips::Tristate::FALSE)
        return rho;
    return lho;
}

vchips::Tristate operator^(const vchips::Tristate &lho, const vchips::Tristate &rho)
{
    return (~lho & rho) | (lho & ~rho);
}

vchips::Tristate operator~(const vchips::Tristate &lho)
{
    if (lho == vchips::Tristate::UNDEFINED)
        return vchips::Tristate::UNDEFINED;
    if (lho == vchips::Tristate::TRUE)
        return vchips::Tristate::FALSE;
    return vchips::Tristate::TRUE;
}

std::ostream &operator<<(std::ostream &stream, const vchips::Tristate &rho)
{
    if (rho == vchips::Tristate::UNDEFINED)
        stream << "U";
    else if (rho == vchips::Tristate::TRUE)
        stream << "1";
    else
        stream << "0";
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const std::vector<vchips::Tristate *> &rho)
{
	bool first = true;

    stream << "[";
    for (auto state : rho) {
        if (state == nullptr)
            continue;
		if (!first)
			stream << ", ";
		else
			first = !first;
        stream << *state;
    }
    stream << "]";
    return stream;
}
