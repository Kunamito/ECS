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
    #include <vector>
    #include <any>

    #include "SparseArray.hpp"
    #include "Entity.hpp"

class Registry {
    public:
        template <typename Component>
        SparseArray<Component>& register_component() {
            _component_array[std::type_index(typeid(Component))] = SparseArray<Component>();
            return _component_array.at(std::type_index(typeid(Component)));
        }

        template <typename Component>
        SparseArray<Component>& get_components() {
            return _component_array.at(std::type_index(typeid(Component)));
        }

        template <typename Component>
        SparseArray<Component> const & get_components() const {
            return _component_array.at(std::type_index(typeid(Component)));
        }

        void killEntity(const Entity& e) {
            for (auto& rm : _remover)
                rm(*this, e);
        }

        template <typename Component>
        typename SparseArray<Component>::reference_type addComponent(const Entity& e, Component&& c) {
            _component_array.at(std::type_index(typeid(Component))).insert_at(e, c);
        }

        // template <typename Component, typename... Params>
        // typename SparseArray<Component>::reference_type emplaceComponent(const Entity& e, Params&&... p) {

        // }

        template <typename Component>
        void removeComponent(const Entity& e) {
            _component_array.at(std::type_index(typeid(Component))).erase(e);
        }

    private:
        std::unordered_map<std::type_index, SparseArray<std::any>> _component_array;
        std::vector<std::function<void(Registry&, const Entity&)>> _remover;
};


#endif
