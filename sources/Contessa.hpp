#include <iostream>
#include <string>
#include "Player.hpp"
// #include "Assassin.hpp"
using namespace std;
namespace coup{
    class Contessa: public Player
    {
    private:
        /* data */
    public:
        Contessa(Game &game, const string &privateName);
        ~Contessa();
        void block(Player &blocked);
    }; 
}