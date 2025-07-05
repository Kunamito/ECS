/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** position.cpp
*/

#include "components/position.hpp"

Position::Position(double value_x, double value_y, double value_z) :
    x(value_x), y(value_y), z(value_z)
{}

Position::Position(const Vector3d& vect) :
    x(vect.x), y(vect.y), z(vect.z)
{}

Position::Position(double value_x, double value_y) :
    x(value_x), y(value_y), z(0.0)
{}

Position::Position(const Vector2d& vect) : 
    x(vect.x), y(vect.y), z(0.0)
{}
