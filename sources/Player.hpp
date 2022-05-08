#pragma once
#include <iostream>
#include <string>
// #include "Game.hpp"
// using namespace std;

namespace coup{
    class Game;
    class Player
    {
    protected:
        
    public:
        Game *game;
        std::string privateName;
        std::string roleName;
        int numsCoins;
        int isDead=0;
        int ind=0;
        Player* killed=NULL;
        Player* Stolen=NULL;
        std::string lastAct;
        Player(Game &game, const std::string &privateName);
        ~Player();
        std::string getName()const;
        std::string role()const;
        int coins()const;
        void income();
        void foreign_aid();
        void coup(Player &p);
    };
    
}