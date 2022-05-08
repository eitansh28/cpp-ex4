#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Assassin: public Player
    {
    private:
        
    public:
        Assassin(Game &game, const string &privateName);
        ~Assassin();
        // void coup(Player &p);
    };
    
}