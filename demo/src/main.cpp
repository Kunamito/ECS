/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** main.cpp
*/

#include <iostream> // test purspose (to delete)

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
    reg.addComponent<Position>(e1, Position(Vector2d(2.1, 4.3)));
    reg.addComponent<Velocity>(e2, Velocity(3));
    std::cout << reg.get_components<Position>()[e1].value_or(Position(0, 0)).x << std::endl;
    std::cout << reg.get_components<Position>()[e2].value_or(Position(0, 0)).y << std::endl;
    std::cout << reg.get_components<Velocity>()[e2].value_or(0) << std::endl;
    return EXIT_SUCCESS;
}
