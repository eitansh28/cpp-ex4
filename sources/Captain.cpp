#include <iostream>
#include <string>
#include "Captain.hpp"
#include "Game.hpp"
using namespace std;
const int MINPLAYER = 2;
const int MAXPLAYER = 6;
const int mustCoup = 10;
namespace coup{
    Captain::Captain(Game &game, const string &privateName):Player(game, privateName){
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
        this->roleName="Captain";
    }
    Captain::~Captain(){}
    
    void Captain::steal(Player &p){
        if(this->numsCoins>=mustCoup){
            throw invalid_argument{"you must coup someone!"};
        }
        if(this->game->getTurnInd()!=this->ind){
            throw invalid_argument{"it's not your turn"};
        }
        if(this->game->online!=2){
            this->game->online=2;
        }
        if(p.numsCoins==1){
            p.numsCoins-=1;
            this->numsCoins+=1;
        }else if(p.numsCoins>=2){
            p.numsCoins-=2;
            this->numsCoins+=2;
        }
        this->lastAct="steal";
        this->Stolen=&p;
        this->game->nextTurn();
    }
    
    void Captain::block(Player &blocked){
        if(this->game->getTurnInd()==blocked.ind){
            throw invalid_argument{"the turn is pasted"};
        }
        if(blocked.lastAct=="steal"){
            blocked.numsCoins-=2;
            blocked.Stolen->numsCoins+=2;
        }else{
            throw invalid_argument{"you can't block this action"};
        }
    }
}