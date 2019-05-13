//
// Created by seth on 5/1/19.
//

#include <iostream>
#include "Indian_Power_Rangers.h"


Indian_Power_Rangers::Indian_Power_Rangers(std::string color) {
    Indian_Power_Rangers::color = color;
    player::resourceName = "Tunuk Tunuk";
    player::resource = 5;
    player::armor = 110;
    player::health = 30;
    player::weaponDmg = 12;
    player::weapon = "Earth Slap";
    player::weaponType = "Energy";
    player::type = "Indian Power Rangers";


}

bool Indian_Power_Rangers::specialAbility(player& target) {
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
            std::cout << "The "<< color << "Indian PowerRanger® did not have enough resource to launch the IED";
            return false;
        }

    }

}

const string &Indian_Power_Rangers::getColor() const {
    return color;
}

void Indian_Power_Rangers::setColor(const string &color) {
    Indian_Power_Rangers::color = color;
}
