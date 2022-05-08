#include "Game.hpp"
#include <iostream>
#include <string>
#include"Player.hpp"
namespace coup{
    Game::Game(){
        vector <Player*> p;
        this->playersList=p;
        this->currTurn=0;
        this->numsPlayers=0;
        this->online=0;
        this->indOfPlayer=0;
    }
    Game::~Game(){}
    vector<std::string> Game::players()const{
        return this->names;
    }
    std::string Game::turn(){
        return this->names.at((unsigned int) (this->currTurn%((int)this->playersList.size())));
    }
    int Game::getTurnInd()const{
        return this->currTurn%((int)this->playersList.size());
    }
    void Game::nextTurn(){
        ++this->currTurn;
        this->currTurn=this->currTurn%((int)this->playersList.size());
    }
    std::string Game::winner(){
        if(this->playersList.size()!=1){
           throw invalid_argument{"the game hasn't finished yet"};
        }if(this->online==0){
            throw invalid_argument{"the game hasn't started yet"};
        }
        return this->playersList.at(0)->privateName;
        }
    int Game::getInd()const{
        return this->indOfPlayer;
    }
    void Game::insertPlayer(Player &player, const std::string &privateName, int ind){
        std::vector<Player*>::iterator it;
        std::vector<std::string>::iterator it2;
        it = this->playersList.begin()+ind;
        this->playersList.insert(it, &player);
        it2 = this->names.begin()+ind;
        this->names.insert(it2, privateName);
        this->numsPlayers++;
        this->indOfPlayer++;
    }
    void Game::deletePlayer(Player &player){
        this->playersList.erase(this->playersList.begin() + player.ind);
        this->names.erase(this->names.begin() + player.ind);
        this->numsPlayers--;
    }
}