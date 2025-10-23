#include <iostream>
#include <stdio.h>
#include "Charmander.h"

//Charmander Constructor

Charmander::Charmander() : Pokemon(){
    type.push_back("Fire");
    skills.push_back("Growl");
    skills.push_back("Scratch");
    
    cout << "Defauly Constructor (Charmander)\n";
}

//New Charmander Constructor

Charmander::Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s)
: Pokemon(name, hp, att, def, t){
    type = t;
    skills = s;
    cout << "Overloaded Constructor (Charmander)\n";
}

//Charmander speaking
void Charmander::speak(){
    cout << "Charmander-char\n";
}

//printStats from parent class (Pokemon) and appends charmander skills 

void Charmander::printStats(){
    Pokemon::printStats();
    cout << "Skills: ";
    for (int i = 0; i < skills.size(); i++){
        cout << skills[i] << "\t";
    }
}
