#include "Team.hpp"
#include <iostream>
#include <limits>



namespace ariel
{
    

    Team::Team(Character *cha): leader_t(cha)
    {
        this->add(cha);
    }


    void Team::add(Character *player)
    {
        if (player == nullptr) {
            throw std::invalid_argument("Invalid player: nullptr");
        }
        if(player->getInside()){
            throw std::runtime_error("already in team");
        }
        if(this->teamates.size() == 10){
            throw std::runtime_error("big team");
        }
        this->teamates.push_back(player);
        player->setInside(true);
    }

Character* Team::getClosest(Point loc){
    Character* newLeader = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (Character* character : this->teamates){
        if (character->isAlive()){
            double distance = character->getLocation().distance(loc);
            if (distance < minDistance){
                newLeader = character;
                minDistance = distance;
            }
        }
    }
    return newLeader;
}


    
    void Team::attack(Team* enemyTeam){
    if(enemyTeam == nullptr){
        throw std::invalid_argument("team is null or dead");
    }
    
    if(enemyTeam->stillAlive() == 0){
        throw std::runtime_error("No living defender left");
    }
    if (this->stillAlive() == 0) {
        throw std::runtime_error("Attacking team is not alive");
    }
    if((enemyTeam->stillAlive() == 0) && (this->stillAlive() == 0))
    {
        throw std::runtime_error("1) Both teams died");
    }
    if(this == enemyTeam)
    {
        throw std::runtime_error("No harm self");
    }
    // Check if the leader of the attacking group is alive
    if (!getTeamLeader()->isAlive())
    {
        // getTeamLeader()->move2(enemyTeam->getTeamLeader()->getLocation()); // Replace 'someNewLocation' with the desired new location
        // Find the nearest living figure as the new leader
        Character* newLeader = getClosest(getTeamLeader()->getLocation());
        if (newLeader == nullptr)
        {
            throw std::runtime_error("No living figures in the attacking group to choose a new leader.");
        }
        setTeamLeader(newLeader);
    }
    Character* victim = enemyTeam->getClosest(getTeamLeader()->getLocation());
    if (victim == nullptr) {
    /*No living figures in the enemy group,
      do something (e.g., return or continue the battle) */
        throw std::runtime_error("No living figures in the enemy group to choose a victim.");
    }
    // Perform the attack
    for (Character* character : this->teamates)
    {
        
        if (!character ->isAlive()){
            continue;
        }

        if(!victim->isAlive()){
            victim = enemyTeam->getClosest(getTeamLeader()->getLocation());
            if(!victim){
                return;
            }
        }
        
        if(Cowboy* cowboy = dynamic_cast<Cowboy*>(character)){
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


    for (Character* character : this->teamates)
    {
        
        if (!character ->isAlive()){
            continue;
        }

        if(!victim->isAlive()){
            victim = enemyTeam->getClosest(getTeamLeader()->getLocation());
            if(!victim){
                return;
            }
        }
        
        if(Ninja* ninja = dynamic_cast<Ninja*>(character)){
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


    int Team::stillAlive()
    {
        int team_Number = 0;
        for (Character* character : this->teamates)
        {
            if( character->isAlive()){
                team_Number++;
            }
        }
        return team_Number;
    }

    void Team::print()
    {
        for (Character* character : this->teamates)
        {
            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(character)){
                cout << character->print() << endl;
            }
        }
        for (Character* character : this->teamates)
        {
            if(Ninja* nin = dynamic_cast<Ninja*>(character)){
                cout << character->print() << endl;
            }
        }
    } 


    Team::~Team(){
        for(Character* character: this->teamates){
            delete character;
        }
        this->leader_t = nullptr;
    }
}