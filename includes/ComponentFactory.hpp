/*
** EPSI PROJECT, 2020
** EPSI_VCHIPS_2020
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
    #define COMPONENTFACTORY_HPP_

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "AbstractComponent.hpp"

namespace vchips {
    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory();

            bool registerComponent(vchips::IComponent *component, const std::string &name);
            std::unique_ptr<vchips::IComponent> createComponent(const std::string &name, const std::string &value) const;
            std::vector<std::string> getNames() const;
            static vchips::ComponentFactory *getFactory();
            void registerPin(vchips::Tristate *pin);

        private:
            std::vector<vchips::Tristate *> pins;
            static vchips::ComponentFactory *singleton;
            std::map<std::string, vchips::IComponent *> instances;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
