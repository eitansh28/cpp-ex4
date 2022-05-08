#include <iostream>
#include <string>
#include "Duke.hpp"
#include "Game.hpp"
using namespace std;
const int MINPLAYER = 2;
const int MAXPLAYER = 6;
const int mustCoup = 10;
namespace coup{
    Duke::Duke(Game &game, const string &privateName):Player(game, privateName) {
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
        this->roleName="Duke";
    }
    Duke::~Duke(){}
    
    void Duke::tax(){
        if(this->numsCoins>=mustCoup){
            throw invalid_argument{"you must coup someone!"};
        }
        if(this->game->getTurnInd()!=this->ind){
            throw invalid_argument{"it's not your turn"};
        }
        if(this->game->online!=2){
            this->game->online=2;
        }
        this->numsCoins+=3;
        this->game->nextTurn();
    }
    void Duke::block(Player &blocked){
        if(this->game->getTurnInd()==blocked.ind){
            throw invalid_argument{"the turn is pasted"};
        }
        if(blocked.lastAct=="foreign_aid"){
            blocked.numsCoins-=2;
        }else{
            throw invalid_argument{"you can't block this action"};
        }
    }
}