//
// Created by seth on 5/1/19.
//

#include <iostream>
#include "Joseph_Stalin.h"
#include <random>

Joseph_Stalin::Joseph_Stalin() {

    player::resourceName = "Communism";
    player::resource = 5;
    player::armor = 110;
    player::health = 30;
    player::weaponDmg = 12;
    player::weapon = "Machine Gun";
    player::weaponType = "Gun";
    player::type = "Joseph Stalin";
    player::name = player::type;

}

bool Joseph_Stalin::specialAbility(player* target) {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0,100);
    double chance  = distribution(generator);
    if(chance >=80) {
        if (resource >= 70 && !dodge(target)) {
            std::uniform_int_distribution<int> distribution1(0,40);
            chance = distribution1(generator)+31;
            target->takeDamage(chance, false);
            this->takeDamage(5, false);
          
            std::cout << "Stalin hit you with an Nuke\n";
            return true;
        }
        else{
            std::cout << "Stalin did not have enough resource to launch the Nuke";
            return false;
        }

    }
    std::cout << "Stalin missed the Nuke\n";
    return false;
}
