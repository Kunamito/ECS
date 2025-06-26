/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** main.cpp
*/

#include "components/position.hpp"
#include "components/drawable.hpp"

#include "Registry.hpp"
#include "project_tools.hpp"

static void loadRegistry(ECS::Registry& reg)
{
    (void)reg.register_component<Position>();
    (void)reg.register_component<Drawable>();
}

int main(int, const char **)
{
    ECS::Registry reg;

    loadRegistry(reg);
    return EXIT_SUCCESS;
}
