/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** 4To16DecoderComponent
*/

#ifndef COMPONENT4_TO_16_DECODER_HPP_
    #define COMPONENT4_TO_16_DECODER_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace vchips {
    class Component4To16Decoder : public vchips::AbstractComponent {
        public:
            Component4To16Decoder();
            std::unique_ptr<vchips::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4_TO_16_DECODER_HPP_ */
