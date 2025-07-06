/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** controle.cpp
*/

#include "systems/controle.hpp"

#include "components/controlable.hpp"

void controle_sys(ECS::Registry& reg)
{
    auto& controlables = reg.getComponents<Controlable>();

    for (size_t e = 0; e < controlables.size(); ++e) {
        
    }
}