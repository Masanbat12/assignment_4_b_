#include "Team.hpp"
#include <vector>

namespace ariel{
    class Team2:public virtual Team{
        
        public:
            Team2(Character*);
            void attack(Team* another) override;
            void print() override;
            // Character* getClosest(Point loc) override;

            ~Team2() override= default;
            Team2(const Team2&) = default;
            Team2& operator=(const Team2&) = default;
            Team2(Team2&&) = default;
            Team2& operator=(Team2&&) = default;

    };
}







