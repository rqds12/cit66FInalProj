//
// Created by sethsan on 5/1/19.
//


#include <iostream>
#include "Salem_Darkmore.h"
#include <random>
using namespace std;
Salem_Darkmore::Salem_Darkmore() {
    player::resourceName = "Darkness";
    player::resource = 5;
    player::armor = 400;
    player::health = 3;
    player::weaponDmg = 19;
    player::weapon = "Nosferatu";
    player::weaponType = "Dark Magic";
    player::type = "Salem Darkmore";
    player::name = player::type;
}

bool Salem_Darkmore::specialAbility(player* target) {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0,100);
    double chance  = distribution(generator);
    if(chance >=80) {
        if (resource >= 70 && !dodge(target)) {
            std::uniform_int_distribution<int> distribution1(0,40);
            chance = distribution1(generator)+31;
            target->setPoisoned(true);


            std::cout << "Darkmore hit you with a strong magical attack that drained your will.\n";

            return target->takeDamage((chance+5), true);
        }
        else{
            std::cout << "The Dark mage didn't have enough " << getResource() << " to kill you today.\n";
            return false;
        }

    }
    return false;
}