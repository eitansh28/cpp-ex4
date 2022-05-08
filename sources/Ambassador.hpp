#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Ambassador: public Player
    {
    private:
        
    public:
        Ambassador(Game &game, const string &privateName);
        ~Ambassador();
        void transfer(Player &send, Player &accept);
        void block(Player &blocked);
    };
     
}