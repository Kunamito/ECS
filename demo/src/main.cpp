/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** main.cpp
*/

#include "components/position.hpp"
#include "components/drawable.hpp"
#include "components/controlable.hpp"
#include "components/velocity.hpp"

#include "Entity.hpp"
#include "Registry.hpp"
#include "project_tools.hpp"

static void loadRegistry(ECS::Registry& reg)
{
    (void)reg.register_component<Position>();
    (void)reg.register_component<Drawable>();
    (void)reg.register_component<Controlable>();
    (void)reg.register_component<Velocity>();
}

int main(int, const char **)
{
    ECS::Registry reg;
    ECS::Entity e1(0);
    ECS::Entity e2(1);

    loadRegistry(reg);
    reg.addComponent<Position>(e1, Position(14.1, 4.3));
    reg.addComponent<Position>(e2, Position(14.1, 4.324234));
    std::cout << reg.get_components<Position>()[e1].value_or(Position(0, 0)).x << std::endl;
    std::cout << reg.get_components<Position>()[e2].value_or(Position(0, 0)).y << std::endl;
    return EXIT_SUCCESS;
}
