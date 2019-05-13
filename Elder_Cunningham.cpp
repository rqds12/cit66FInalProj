//
// Created by sethsan on 5/1/19.
//


#include <iostream>
#include "Elder_Cunningham.h"
using namespace std;
Elder_Cunningham::Elder_Cunningham() {
    player::resourceName = "Free Bibles";
    player::resource = 5;
    player::armor = 400;
    player::health = 3;
    player::weaponDmg = 19;
    player::weapon = "Door to Door Evangelizing";
    player::weaponType = "Religious Teaching";
    player::type = "Elder Cunningham";
}

bool Elder_Cunningham::specialAbility(player* target) {
    srand(time(NULL));
    double chance  = (rand()%100)+1;
    if(chance >=80) {
        if (resource >= 70) {
            chance = (rand()%40)+31;
            target->setPoisoned(true);
            target->takeDamage((chance+5), true);

            std::cout << "The elder hit you with a massive guilt trip and a free bible.\nYou are going to church with him on wednesday and you can feel your willpower draining quickly.";
            return true;
        }
        else{
            std::cout << "The good elder didn't have enough " << getResource() << " to evangelize you today.\n";
            return false;
        }

    }
    return false;
}