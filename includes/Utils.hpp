/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

#include <iostream>

namespace vchips {
    struct Debug { };

    extern vchips::Debug debug;
}

template<typename T>
vchips::Debug& operator<<(vchips::Debug &s, const T &x)
{
#   ifdef DEBUG
    std::cout << x;
#   else
    (void) x;
#   endif
  return s;
}

vchips::Debug& operator<<(vchips::Debug &s, std::ostream& (*f)(std::ostream &));
vchips::Debug& operator<<(vchips::Debug &s, std::ostream& (*f)(std::ios &));
vchips::Debug& operator<<(vchips::Debug &s, std::ostream& (*f)(std::ios_base &));

#endif /* !UTILS_HPP_ */
