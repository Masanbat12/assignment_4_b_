
#include "Ninja.hpp"
#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
namespace ariel
{
    constexpr int OLD_NINJA_HP = 150;
    constexpr int OLD_NINJA_SPEED = 8;
    class OldNinja : public Ninja
    {
        public:
            OldNinja(string _name, Point locat):Ninja(std::move(_name),locat,OLD_NINJA_HP,OLD_NINJA_SPEED){};
    };
}
#endif