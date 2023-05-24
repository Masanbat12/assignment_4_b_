#include "Ninja.hpp"
#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

namespace ariel
{
    constexpr int T_NINJA_HP = 120;
    constexpr int T_NINJA_SPEED = 12;
    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja(string _name, Point locat):Ninja(std::move(_name),locat,T_NINJA_HP,T_NINJA_SPEED){};

    };
}
#endif