#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Duke: public Player
    {
    private:
        
    public:
        Duke(Game &game, const string &privateName);
        ~Duke();
        void tax();
        void block(Player &blocked);
    };
    
    
}