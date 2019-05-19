//created by Erik
#include "Rogue.h"
#include "Enemy.h"
#include <ctime>
#include <iostream>
#include <random>
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
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0,10);
    double chance = (distribution(generator)) / 10;
    if (this->resource >= 45 && !dodge(target)) {
        if (chance >= 0.4 && chance <= 0.6) {
            target->setPoisoned(true);
            target->takeDamage(target->getHealth() - ((target->getHealth() * chance)+15), true);
            cout << this->getName() << " throws oliander powder in " << target->getName() << "'s soup and the become ill."<<endl;
        }
        else{
            cout << this->getName() << " sticks " << target->getName() << " with a " << this->getWeapon() << endl;
            target->takeDamage((chance*10+30),0);
        }
        setResource(getResource()-getResourceReq());

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
    this->setResource(this->getResource()+rage);
    return player::takeDamage(dmg, ispoison);
}

