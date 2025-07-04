/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** position.hpp
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_

struct Position {
    Position(float value_x, float value_y) : x(value_x), y(value_y) {}
    float x;
    float y;
};

#endif 
