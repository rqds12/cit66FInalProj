//
// Created by Seth on 5/1/2019.
//

#include "Rogue.h"
#include "Enemy.h"
#include <ctime>
Rogue::Rogue(string& name) {
    player::name = name;
    player::weapon = "Knife";
    player::health = 150;
    player::resourceName = "Anger";
    player::resource = 0;
    player::armor =25;
    player::weaponDmg = 34;
}

bool Rogue::specialAbility(Enemy& target) {
    srand(time(NULL));

    double chance = ((rand() % 10) + 1) / 10;
    if (this->resource >= 45) {
        if (chance >= 0.4 && chance <= 0.6) {
            target.setPoisoned(true);

            target.takeDamage(target.getHealth() - (target.getHealth() * chance), true);
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