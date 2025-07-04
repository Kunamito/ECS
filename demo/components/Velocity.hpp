/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** Velocity.hpp
*/

#ifndef VELOCITY_HPP_
    #define VELOCITY_HPP_
    #include <tuple>

struct Velocity {
    std::tuple<float> direction;
    float speed;
};
