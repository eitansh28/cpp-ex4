#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Captain: public Player
    {
    private:
        
    public:
        Captain(Game &game, const string &privateName);
        ~Captain();
        void steal(Player &p);
        void block(Player &blocked);
    };
      
}