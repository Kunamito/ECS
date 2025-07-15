/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** event.cpp
*/

#include <SFML/Window/Event.hpp>

#include "systems/event.hpp"
#include "components/window.hpp"

void manageEvent(ECS::Registry& reg)
{
    std::optional<std::reference_wrapper<Window>> opt_win = findActiveWindow(reg.getComponents<Window>());
    if (!opt_win.has_value())
        return;
        
    sf::Event event = {};
    std::reference_wrapper<Window> win = opt_win.value();

    if (win.get().isOpen()) {
        while(win.get().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.get().close();
        }
    }
}
