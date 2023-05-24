#include "Team2.hpp"
#include "Team.hpp"
#include <iostream>
#include <cmath>
#include <limits>

namespace ariel
{
    Team2::Team2(Character *cha):Team(cha){}

    void Team2::attack(Team *enemyTeam)
    {
        if (!enemyTeam)
        {
            throw std::invalid_argument("Invalid enemy team");
        }
        if (enemyTeam->stillAlive() == 0)
        {
            throw std::runtime_error("No living enemy left");
        }
        // if (this->stillAlive() == 0) {
        //     throw std::runtime_error("Attacking team is not alive");
        // }

        // Check if the leader of the attacking group is alive
        if (!this->getTeamLeader()->isAlive())
        {
            // getTeamLeader()->move2(enemyTeam->getTeamLeader()->getLocation()); // Replace 'someNewLocation' with the desired new location
            // Find the nearest living figure as the new leader
            Character *newLeader = getClosest(getTeamLeader()->getLocation());
            if (newLeader == nullptr)
            {
                throw std::runtime_error("No living figures in the attacking group to choose a new leader.");
            }
            setTeamLeader(newLeader);
        }
        Character *victim = enemyTeam->getClosest(getTeamLeader()->getLocation());
        if (victim == nullptr)
        {
            throw std::runtime_error("No living figures in the enemy group to choose a victim.");
        }
        // Perform the attack
        for (Character *character : getTeamates())
        {
            if (!character->isAlive())
            {
                continue;
            }

            if (!victim->isAlive())
            {
                victim = enemyTeam->getClosest(getTeamLeader()->getLocation());
                if (!victim)
                {
                    return;
                }
            }

            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(character))
            {
                if (cowboy != nullptr && cowboy->isAlive())
                {
                    if (cowboy->hasboolets())
                    {
                        cowboy->shoot(victim);
                    }
                    else
                    {
                        cowboy->reload();
                    }
                }
            }
            if (Ninja *ninja = dynamic_cast<Ninja *>(character))
            {
                if (ninja->distance(victim) <= 1.0)
                {
                    ninja->slash(victim);
                }
                else
                {
                    ninja->move(victim);
                }
            }
        }
    }

    void Team2::print()
    {
        string output = "";
        for (size_t m = 0; m < getTeamates().size(); m++)
        {
            cout << getTeamates()[m]->print() <<endl;
        }
    }

}