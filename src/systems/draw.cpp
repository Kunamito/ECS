/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** draw.cpp
*/

#include <iostream>

#include "systems/draw.hpp"

#include "components/drawable.hpp"
#include "components/position.hpp"
#include "components/sprite.hpp"

void draw_sys(ECS::Registry& reg)
{
    auto& sprites = reg.getComponents<Sprite>();
    auto& drawables = reg.getComponents<Drawable>();
    auto& positions = reg.getComponents<Position2>();

    for (size_t e = 0; e < sprites.size(); ++e) {
        if (sprites[e].has_value() && drawables[e].has_value() && positions[e].has_value()) {
            auto& sprite = sprites[e].value();
            auto& win = drawables[e].value().target;
            auto& pos = positions[e].value();

            sprite.setPosition(pos);
            win.get().draw(sprite);
        }
    }
}
