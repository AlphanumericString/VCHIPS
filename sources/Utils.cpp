/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** Utils
*/

#include "Utils.hpp"

vchips::Debug vchips::debug = vchips::Debug();

vchips::Debug& operator<<(vchips::Debug &s, std::ostream& (*f)(std::ostream &))
{
#ifdef DEBUG
    f(std::cout);
#else
    (void) f;
#endif
    return s;
}

vchips::Debug& operator<<(vchips::Debug &s, std::ostream& (*f)(std::ios &))
{
#ifdef DEBUG
    f(std::cout);
#else
    (void) f;
#endif
    return s;
}

vchips::Debug& operator<<(vchips::Debug &s, std::ostream& (*f)(std::ios_base &))
{
#ifdef DEBUG
    f(std::cout);
#else
    (void) f;
#endif
    return s;
}