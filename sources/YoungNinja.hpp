#include "Ninja.hpp"
#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
namespace ariel
{
    constexpr int Y_NINJA_HP = 100;
    constexpr int Y_NINJA_SPEED = 14;
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string _name, Point locat):Ninja(std::move(_name),locat,Y_NINJA_HP,Y_NINJA_SPEED){};
    };
}
#endif