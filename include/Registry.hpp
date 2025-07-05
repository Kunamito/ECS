/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** Registry.hpp
*/

#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include <unordered_map>
    #include <typeindex>
    #include <functional>
    #include <any>

    #include "tools/SparseArray.hpp"
    #include "Entity.hpp"

namespace ECS {

class Registry {
    public:
        template <typename Component>
        SparseArray<Component>& register_component() {
            _component_array.insert_or_assign(std::type_index(typeid(Component)), SparseArray<Component>());
            return std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component))));
        }

        template <typename Component>
        SparseArray<Component>& get_components() {
            return std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component))));
        }

        template <typename Component>
        SparseArray<Component> const & get_components() const {
            return std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component))));
        }

        void killEntity(const Entity& e);

        template <typename Component>
        void addComponent(const Entity& e, Component&& c) {
            std::any_cast<SparseArray<Component>&>(_component_array.at(std::type_index(typeid(Component)))).insert_at(e, c);
        }

        // template <typename Component, typename... Params>
        // typename SparseArray<Component>::reference_type emplaceComponent(const Entity& e, Params&&... p) {

        // }

        template <typename Component>
        void removeComponent(const Entity& e) {
            std::any_cast<SparseArray<Component>>(_component_array.at(std::type_index(typeid(Component)))).erase(e);
        }

    private:
        std::unordered_map<std::type_index, std::any> _component_array;
        std::vector<std::function<void(Registry&, const Entity&)>> _remover;
};

} // namespace ECS

#endif
