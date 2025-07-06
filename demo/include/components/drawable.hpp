/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** drawable.hpp
*/

#ifndef DRAWABLE_HPP_
    #define DRAWABLE_HPP_

    #include <SFML/Graphics/RenderWindow.hpp>

struct Drawable {
    Drawable(sf::RenderWindow&);
    std::reference_wrapper<sf::RenderWindow> target;
};

#endif
