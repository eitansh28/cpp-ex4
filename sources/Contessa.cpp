#include <iostream>
#include <string>
#include "Contessa.hpp"
#include "Game.hpp"

using namespace std;
const int MINPLAYER = 2;
const int MAXPLAYER = 6;
const int mustCoup = 10;
namespace coup{
    Contessa::Contessa(Game &game, const string &privateName):Player(game, privateName){
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
        this->roleName="Contessa";
    }
    Contessa::~Contessa(){}
    
    void Contessa::block(Player &blocked){
        if(this->game->getTurnInd()==blocked.ind){
            throw invalid_argument{"the turn is pasted"};
        }
        if(blocked.lastAct=="killing"){
            Player temp=*(blocked.killed);
            for(Player* pl: this->game->playersList){
            if(pl->ind>=temp.ind){
                pl->ind++;
            }
        }this->game->insertPlayer(temp, temp.privateName, temp.ind);
        }else{
            throw invalid_argument{"you can't block this action"};
        }

        if(blocked.killed->ind<(int)this->game->getTurnInd()){
            this->game->nextTurn();
        }blocked.killed->isDead=0;
    }
}