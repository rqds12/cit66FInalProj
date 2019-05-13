//
// Created by sethsan on 5/1/19.
//
using namespace std;

#include <iostream>
#include "Elder_Cunningham.h"
Elder_Cunningham::Elder_Cunningham() {
    player::resourceName = "Free Bibles";
    player::resource = 5;
    player::armor = 400;
    player::health = 3;
    player::weaponDmg = 19;
    player::weapon = "Door to Door Evangelizing";
    player::weaponType = "Religious Teaching";
}

bool player::specialAbility(player *target) {
    srand(time(NULL));
    double chance  = (rand()%100)+1;
    if(chance >=80) {
        if (resource >= 70) {
            chance = (rand()%40)+31;
            target.takeDamage(chance, false);
            this->takeDamage(5, false);

            std::cout << "The "<< color << " Indian PowerRanger® hit you with an IED\n";
            return true;
        }
        else{
            std::cout << "The good elder didn't have enough " << getResource() << " to evangelize you today.";
            return false;
        }

    }
    return false;

}