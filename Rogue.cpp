//
// Created by Seth on 5/1/2019.
//

#include "Rogue.h"
#include "Enemy.h"
#include <ctime>
Rogue::Rogue(string& name) {
    player::name = name;
    player::weapon = "Rusty Pointy Thing";
    player::health = 159;
    player::resourceName = "Anger";
    player::resource = 40;
    player::armor =15;
    player::weaponType = "Rusty Dagger";
    player::weaponDmg = 8;
    player::type = "Rogue";
    player::agility = 40;
    player::money = 5;
}

bool Rogue::specialAbility(player *target) {
    srand(time(NULL));

    double chance = ((rand() % 10) + 1) / 10;
    if (this->resource >= 45) {
        if (chance >= 0.4 && chance <= 0.6) {
            target->setPoisoned(true);

            target->takeDamage(target->getHealth() - (target->getHealth() * chance), true);
        }

    }
    return false;
}

bool Rogue::read() {
    std::string temp;
    reader.open("../RogueStory.txt");
    if (reader.is_open()) {
        while(reader.good()) {

            getline(reader, temp, '|');
            storyLine.push_back(temp);
            if(reader.bad()){
                break;
            }
        }
    }
    return true;
}

bool Rogue::takeDamage(double dmg, bool ispoison) {
    double rage = (dmg * 2);
    (ispoison) ? rage*0.95 : rage*1.2;
    this->setResource(rage);
    return player::takeDamage(dmg, ispoison);
}

