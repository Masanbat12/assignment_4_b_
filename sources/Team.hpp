#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Character.hpp"
#include <vector>


namespace ariel
{
    class Team
    {
        private:
            vector<Character*> teamates;
            Character* leader_t;
        protected:
            Character* getTeamLeader() const {
                return leader_t;
            }
            void setTeamLeader(Character* new_l) {
                leader_t = new_l;
            }
            vector<Character*> getTeamates() const {
                return this->teamates;
            }

        public:
            Team(Character*);
            virtual void attack(Team* other);
            virtual void print();
            void add(Character* Character);
            int stillAlive();
            Character* getClosest(Point p);
            
            
            virtual ~Team();
            Team(const Team&) = default;
            Team& operator=(const Team&) = default;
            Team(Team&&) = default;
            Team& operator=(Team&&) = default;
    };
}