#include <iostream>
#include <string>
#include "Player.hpp"
#include <vector>
#include "Game.hpp"
using namespace std;
const int MINPLAYER = 2;
const int mustCoup = 10;
const int canCoup = 7;
namespace coup{
    Player::Player(Game &game, const std::string &privateName){
        this->game=&game;
        this->privateName=privateName;
        this->numsCoins=0;
    }
    Player::~Player(){}
    std::string Player::getName()const{
        return this->privateName;
    }
    std::string Player::role()const{return this->roleName;}
    int Player::coins()const{return this->numsCoins;}
    void Player::income(){
        if(this->game->getInd()<MINPLAYER){
            throw invalid_argument{"need at least two players to play"};
        }
        if(this->numsCoins>=mustCoup){
            throw invalid_argument{"you must coup someone!"};
        }
        if(this->game->getTurnInd()!=this->ind){
            throw invalid_argument{"it's not your turn"};
        }
        if(this->game->online!=2){
            this->game->online=2;
        }
        this->numsCoins++;
        this->game->nextTurn();
        this->lastAct="income";
    }
    void Player::foreign_aid(){
        if(this->game->getInd()<MINPLAYER){
            throw invalid_argument{"need at least two players to play"};
        }
        if(this->numsCoins>=mustCoup){
            throw invalid_argument{"you must coup someone!"};
        }
        if(this->game->getTurnInd()!=this->ind){
            throw invalid_argument{"it's not your turn"};
        }
        if(this->game->online!=2){
            this->game->online=2;
        }
        this->numsCoins+=2;
        this->game->nextTurn();
        this->lastAct="foreign_aid";
    }
    void Player::coup(Player &p){
        if(this->game->getTurnInd()!=this->ind){
            throw invalid_argument{"it's not your turn"};
        }
        if(p.isDead==1){
            throw invalid_argument{"this player already dead"};
        }
        if(this->game->online!=2){
            this->game->online=2;
        }
        if(this->role()=="Assassin" && this->numsCoins>=3 && this->numsCoins<canCoup){
            this->game->deletePlayer(p);
            this->lastAct="killing";
            this->killed=&p;
            this->numsCoins-=3;
            p.isDead=1;
            if(p.ind>this->ind){
                this->game->nextTurn();
            }
            for(Player* pl: this->game->playersList){
                if(pl->ind>p.ind){
                    pl->ind--;
                }
            }
        }
        else if(this->numsCoins<canCoup){
            throw invalid_argument{"you need at least 7 coins"};
        }
        else{
            this->game->deletePlayer(p);
            this->numsCoins-=canCoup;
            p.isDead=1;
            if(p.ind>this->ind){
                this->game->nextTurn();
            }
            
            for(Player* pl: this->game->playersList){
                if(pl->ind>p.ind){
                    pl->ind--;
                }
            }
        }
        
    }

}