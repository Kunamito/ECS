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
    #include <any>

    #include "SparseArray.hpp"

class Registry {
    public:
        template <class Component>
        SparseArray<Component>& register_component() {
            _component_array[std::type_index(typeid(Component))] = SparseArray<Component>();
            return _component_array.at(std::type_index(typeid(Component)));
        }

        template <class Component>
        SparseArray<Component>& get_components() {
            return _component_array.at(std::type_index(typeid(Component)));
        }

        template <class Component>
        SparseArray<Component> const & get_components() const {
            return _component_array.at(std::type_index(typeid(Component)));
        }

    private:
        std::unordered_map<std::type_index, SparseArray<std::any>> _component_array;
};

#endif
