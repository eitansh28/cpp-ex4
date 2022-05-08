#include <iostream>
#include <string>
#include "Ambassador.hpp"
#include "Game.hpp"
using namespace std;
const int MINPLAYER = 2;
const int MAXPLAYER = 6;
const int mustCoup = 10;
namespace coup{
    Ambassador::Ambassador(Game &game, const string &privateName):Player(game, privateName){
        if(game.getInd()>=MAXPLAYER){
            throw invalid_argument{"too much players"};
        }
        if(this->game->online==2){
            throw invalid_argument("the game started already");
        }
        this->ind=game.getInd();
        game.insertPlayer(*this, privateName, this->ind);
        if(game.getInd()>=2){
            game.online=1;
        }
        this->roleName="Ambassador";
    }
    Ambassador::~Ambassador(){}
    
    void Ambassador::transfer(Player &send, Player &accept){
        if(this->numsCoins>=mustCoup){
            throw invalid_argument{"you must coup someone!"};
        }
        if(this->game->getTurnInd()!=this->ind){
            throw invalid_argument{"it's not your turn"};
        }
        if(send.numsCoins<1){
            throw invalid_argument{"you can't transfer from him"};
        }
        if(this->game->online!=2){
            this->game->online=2;
        }
        send.numsCoins--;
        accept.numsCoins++;
        this->lastAct="transfer";
        this->game->nextTurn();
    }
    
    void Ambassador::block(Player &blocked){
        if(this->game->getTurnInd()==blocked.ind){
            throw invalid_argument{"the turn is pasted"};
        }
        if(blocked.lastAct=="steal"){
            blocked.numsCoins-=2;
            blocked.Stolen->numsCoins+=2;
        }
    }
}
    