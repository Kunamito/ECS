/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** position.hpp
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_

    #include "tools/Vector3.hpp"
    #include "tools/Vector2.hpp"

struct Position {
    Position() = default;
    Position(double value_x, double value_y, double value_z);
    Position(const Vector3d&);
    Position(double value_x, double value_y);
    Position(const Vector2d&);

    double x;
    double y;
    double z;
};

#endif 
