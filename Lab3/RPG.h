//RPG.h
#include <iostream>
#include <string>
#include <random>
#ifndef RPG_H
#define RPG_H
using namespace std;

class RPG {
    public:
    //constructors
    RPG();
    RPG(string name, int hits_taken, float luck, float exp, int level);

    //mutators
    bool isAlive() const;
    void setHitsTaken (int new_hits);

    //accessors
    string getName() const;
    int gethitsTaken() const;
    float getLuck() const;
    float getExp() const;
    int getLevel() const;

    //COMPLETE THE REST
    private:
    string name;
    int hits_taken;
    float luck;
    float exp;
    int level;

    //Coding Assignment 4 Modifications
    void RPG::setName(string name){
        this -> name = name;
    }

    void RPG::updateExplevel(){
        exp += 50.0;
        if (exp >= 100.0){
            level += 1;
            exp = 0.0;
            luck +=0.1;
        }
    }

    void RPG :: attack(RPG * opponent){
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dis(0.0, 0.1);
        float random_num = dis(gen);

        const float HIT_FACTOR = 0.5;

        bool hit = random_num > HIT_FACTOR * opponent -> getLuck();
        if (hit){
           int battle_result_hit = opponent -> gethitsTaken();
           opponent -> setHitsTaken(battle_result_hit + 1);
        }
    }

    void RPG :: printStats(){
        bool alive = isAlive();
        cout << "Name: " << name << "\tHits Taken: "<< hits_taken << "\tLuck: " << luck << "\tExp: " << exp << "\tLevel: " << level;
        if (alive){
            cout << "\tStatus: Alive";
        }
        else{
            cout << "\tStatus: Dead:";
        }
        cout << endl;
    }
    RPG::~RPG(){
    }
};
#endif