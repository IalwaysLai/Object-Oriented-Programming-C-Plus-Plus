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

void Game :: endRound(RPG* winner, RPG* loser, int loserIndex){
    (winner) -> setHitsTaken(0);
    live_players.erase(loserIndex);
    (winner) -> updateExplevel();
    cout << "NPC_"<< (winner) -> getName() << " won against " << loser -> getName() << endl;
}

void Game :: battleRound(){
    int playerIndex1 = selectPlayers();
    int playerIndex2 = selectPlayers();
    if (playerIndex1 == playerIndex2){
        battleRound();
        return;
    }
    RPG* player1 = players[playerIndex1];
    RPG* player2 = players[playerIndex2];

    while (player1 -> isAlive() && player2 -> isAlive()){
        player1 -> attack(player2);
        if (player2 -> isAlive()){
            player2 -> attack(player1);
        }
    }
    if (player1 -> isAlive()){
        RPG* winner = player1;
        RPG* loser = player2;
        int loserIndex = playerIndex2;
        endRound(winner, loser, loserIndex);
    }
    else{
        RPG* winner = player2;
        RPG* loser = player1;
        int loserIndex = playerIndex1;
        endRound(winner, loser, loserIndex);
    }
}

void Game :: gameLoop(){
    while(live_players.size() > 1){
        battleRound();
    }
}

void Game :: printFinalResults(){
    for (int i = 0; i < players.size(); i++){
        cout << i << ": ";
        players[i] -> printStats();
    }
}

Game :: ~Game(){}


