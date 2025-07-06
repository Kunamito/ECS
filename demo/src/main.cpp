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

#include "systems/draw.hpp"
#include "systems/movement.hpp"

#include "Entity.hpp"
#include "Registry.hpp"
#include "project_tools.hpp"

void gravity_sys(ECS::Registry& reg)
{
    auto& positions = reg.getComponents<Position2>();
    auto& velocities = reg.getComponents<Velocity2>();

    for (ECS::Entity e = 0; e < positions.size() && e < velocities.size(); ++e) {
        if (positions[e].has_value() && velocities[e].has_value()) {
            auto& pos = positions[e].value();
            auto& vel = velocities[e].value();

            if (pos.y <= 700) {
                vel.y += 0.5f;
                if (pos.x < 0)
                    vel.x += 0.1;
                else if (pos.x > 0)
                    vel.x -= 0.1;
            } else {
                vel.y = 0.0f;
                vel.x = 0.0f;
            }
        }
    }
}

static void loadRegistry(ECS::Registry& reg)
{
    (void)reg.registerComponent<Position2>();
    (void)reg.registerComponent<Velocity2>();
    (void)reg.registerComponent<Sprite>();
    (void)reg.registerComponent<Controlable>();
    (void)reg.registerComponent<Drawable>();

    reg.addSystem(&draw_sys);
    reg.addSystem(&movement2_sys);
    reg.addSystem(&gravity_sys);
}

static void demoSetup(ECS::Registry& reg, sf::RenderWindow& window)
{
    ECS::Entity e1(0);
    ECS::Entity e2(1);

    (void)reg.addComponent<Position2>(e1, Position2(300.0f, 300.0f));
    (void)reg.addComponent<Sprite>(e1, Sprite("assets/test.png"));
    (void)reg.addComponent<Drawable>(e1, Drawable(window));
    (void)reg.addComponent<Velocity2>(e1, Velocity2(10.0f, 0.0f));

    (void)reg.addComponent<Position2>(e2, Position2(200.0f, 200.0f));
    (void)reg.addComponent<Sprite>(e2, Sprite("assets/test.png"));
    (void)reg.addComponent<Drawable>(e2, Drawable(window));
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
