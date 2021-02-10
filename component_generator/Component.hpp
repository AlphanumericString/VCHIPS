/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** {0}Component
*/

#ifndef COMPONENT{1}_HPP_
    #define COMPONENT{1}_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {{
    class Component{0} : public vchips::AbstractComponent {{
        public:
            Component{0}();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    }};
}}

#endif /* !COMPONENT{1}_HPP_ */
