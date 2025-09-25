//RPG.h
#include <string>
#ifndef RPG_H
#define RPG_H
using namespace std;
const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN = 3;

class RPG{
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
    //COMPLETE THE REST
};
#endif