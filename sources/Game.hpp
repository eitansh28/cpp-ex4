#pragma once
#include <iostream>
#include <string>
#include <vector>
// #include "Player.hpp"
using namespace std;
    
namespace coup{
    class Player;
    class Game
    {
        
    private:
        
        unsigned int numsPlayers;
        int currTurn;
        int indOfPlayer;
    public:
        vector <Player*> playersList;
        vector <string> names;
        int online;
        Game(/* args */);
        ~Game();
        vector<string> players()const;
        string turn();
        int getTurnInd()const;
        void nextTurn();
        string winner();
        int getInd()const;
        void insertPlayer(Player &player, const std::string &privateName, int ind);
        void deletePlayer(Player &player);
    };
}