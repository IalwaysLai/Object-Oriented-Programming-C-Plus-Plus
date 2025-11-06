//Game.cpp
#include "Game.h"
#include <random>
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

int Game :: selectPlayers(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() -1);
    int randomIndex = dist(gen);
    set<int>::iterator it = live_players.begin();
    advance (it, randomIndex);
    int selectedIndex = *it;
    return selectedIndex;
}

