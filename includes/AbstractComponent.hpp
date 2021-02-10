/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** AbstractComponent
*/

#ifndef ABSTRACTCOMPONENT_HPP_
    #define ABSTRACTCOMPONENT_HPP_

#include <vector>
#include <map>
#include <list>
#include "IComponent.hpp"

namespace vchips {
    class AbstractComponent : public vchips::IComponent {
        public:
            ~AbstractComponent();
            AbstractComponent();
            AbstractComponent(const AbstractComponent &);
            vchips::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, vchips::IComponent &other, std::size_t otherPin) override;
            void setPinAt(std::size_t pin, vchips::Tristate value);
            void dump() const;
            vchips::Tristate getOutput() const;

        protected:
            void recomputeGraph(vchips::Tristate *oldPtr, vchips::Tristate *newPtr);
            void setName(const std::string &name);
            std::vector<vchips::Tristate *> pins;
            std::vector<std::unique_ptr<vchips::IComponent>> gatesToUpdate;
        private:
            std::string name;

    };
}

#endif /* !ABSTRACTCOMPONENT_HPP_ */
