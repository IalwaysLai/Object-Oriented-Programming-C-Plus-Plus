//Game.cpp
#include "Game.h"
using namespace std;

Game::Game(){
}

void Game :: generatePlayers(int n){
    for (int i = 0; i < n; i++){
        players.push_back(new RPG());
        string new_name = "NPC"+to_string(i);
        players[i] -> setName(new_name);
        live_players.insert(i);
    }
}