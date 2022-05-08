#include <iostream>
#include <string>
#include "Assassin.hpp"
#include "Game.hpp"
using namespace std;
const int MINPLAYER = 2;
const int MAXPLAYER = 6;
const int mustCoup = 10;
namespace coup{
    Assassin::Assassin(Game &game, const string &privateName):Player(game, privateName){
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
        this->roleName="Assassin";
    }
    Assassin::~Assassin(){}
    
    // void Assassin::coup(Player &p){
    //     if(this->game->getTurnInd()!=this->ind){
    //         throw invalid_argument{"it's not your turn"};
    //     }
    //     if(this->numsCoins<3){
    //         throw invalid_argument{"you need at least 3 coins"};
    //     }else if(this->numsCoins>=3 && this->numsCoins<7){
    //         this->game->deletePlayer(p);
    //         this->lastAct="killing";
    //         this->killed=&p;
    //         this->numsCoins-=3;
    //         this->game->nextTurn();
    //     }else{
    //         this->game->deletePlayer(p);
    //         this->numsCoins-=7;
    //         this->game->nextTurn();
    //         // this->game->currTurn++;
    //     }
    //     for(Player* pl: this->game->playersList){
    //         if(pl->ind>p.ind){
    //             pl->ind--;
    //         }
    //     }
    // }
}