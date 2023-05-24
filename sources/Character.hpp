#pragma once
#include "Point.hpp"
#include <string>
#include <stdexcept>
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

constexpr int hundred = 100;
using namespace std;
namespace ariel 
{
    class Character
    {
        private:
            int life;
            string name;
            bool inside = false;
            Point place;
        protected:
            Point getPlace(){
                return this->place;
            }

        public:
            virtual ~Character() = default;
            Character() = delete;
            Character(const Character&) = delete;
            Character(const Character&&) = delete;
            Character& operator=(const Character&) = delete;
            Character& operator=(const Character&&) = delete;// move constructor

            Character(string _name, Point location, int health);
            bool isAlive();
            double distance(Character* other_char);
            void hit(int dam);
            virtual string print() = 0;
            string getName() const { return name; }
            Point  getLocation() const { return place;}
            int    getLife() const { return life;}
            bool getInside() const { return inside;}
            void setInside(bool enter) {  inside = enter;}
            // void    move2(Point newLocation);
    };
}
#endif