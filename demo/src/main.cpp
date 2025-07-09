/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** main.cpp
*/

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "components/position.hpp"
#include "components/sprite.hpp"
#include "components/controlable.hpp"
#include "components/velocity.hpp"
#include "components/drawable.hpp"
#include "components/gravity.hpp"

#include "systems/draw.hpp"
#include "systems/movement.hpp"
#include "systems/gravity.hpp"

#include "Entity.hpp"
#include "Registry.hpp"
#include "project_tools.hpp"

static void loadRegistry(ECS::Registry& reg)
{
    (void)reg.registerComponent<Position2>();
    (void)reg.registerComponent<Velocity2>();
    (void)reg.registerComponent<Sprite>();
    (void)reg.registerComponent<Controlable>();
    (void)reg.registerComponent<Drawable>();
    (void)reg.registerComponent<Gravity>();

    reg.addSystem(&draw_sys);
    reg.addSystem(&movement2_sys);
    reg.addSystem(&gravity_sys);
}

static void demoSetup(ECS::Registry& reg, sf::RenderWindow& window)
{
    ECS::Entity e1(0);
    ECS::Entity e2(1);

    (void)reg.addComponent<Position2>(e1, Position2(600.0f, 400.0f));
    (void)reg.addComponent<Sprite>(e1, Sprite("assets/test.png"));
    (void)reg.addComponent<Drawable>(e1, Drawable(window));
    (void)reg.addComponent<Velocity2>(e1, Velocity2(10.0f, 0.0f));
    (void)reg.addComponent<Gravity>(e1, Gravity());

    (void)reg.addComponent<Position2>(e2, Position2(600.0f, 300.0f));
    (void)reg.addComponent<Sprite>(e2, Sprite("assets/test.png"));
    (void)reg.addComponent<Drawable>(e2, Drawable(window));
    (void)reg.addComponent<Velocity2>(e2, Velocity2(-10.0f, 0.0f));
}

int main(int, const char **)
{
    ECS::Registry reg;
    sf::RenderWindow win(sf::VideoMode({1280, 720}), "DEMO");
    sf::Event event;
    
    win.setFramerateLimit(30);
    loadRegistry(reg);
    demoSetup(reg, win);

    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear();
        reg.runSystems();
        win.display();
    }
    return EXIT_SUCCESS;
}
