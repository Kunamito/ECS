/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** Registry.cpp
*/

#include "Registry.hpp"

namespace ECS {

void Registry::killEntity(const Entity& e)
{
    for (auto& rm : _remover)
        rm(*this, e);
}

} // namespace ECS

