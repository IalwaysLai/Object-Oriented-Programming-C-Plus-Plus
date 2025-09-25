//main.cpp
#include <iostream>
#include "RPG.h"
using namespace std;

int main(){
    //Ask professor question about different RPG constructors. If one is defined and one not, are they separate entities with the same name?
    RPG p1 = RPG("Wizard", 0, 0.2, 60, 1);
    RPG p2 = RPG();
    //Why is c_str() necessary?
    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f \t Level: %i\n", p1.gethitsTaken(), p1.getLuck(), p1.getExp(), p1.getLevel());

    //PRINT the same for p2
    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f \t Level: %i\n", p2.gethitsTaken(), p2.getLuck(), p2.getExp(), p2.getLevel());

    //CALL setHitsTaken(new_hit) on either p1 and p2
    int new_hit = 3;
    p2.setHitsTaken(new_hit);

    cout << "\nP2 hits taken ";
    //PRINT out the hits_taken

    cout << "0 is dead, 1 is alive\n";
    //CALL isAlive() on both p1 and p2
    cout << p1.getName()<< p1.isAlive() << endl;
    cout << p2.getName()<< p2.isAlive() << endl;
    return 0;
}
