//
// Created by sethsan on 5/13/19.
//

#include "Gunslinger.h"
bool Gunslinger::specialAbility(player *target) {
    return false;
}

bool Gunslinger::takeDamage(double dmg, bool ispoison) {
    return false;
}

bool Gunslinger::read() {
    return false;
}

Gunslinger::Gunslinger(string &name){
    player::name = name;
    player::type = "Gunslinger";
    player::weapon = "Bang Bang Shootem' up";
    player::weaponType = "6 Shooter";
    player::health = 15;
    player::resourceName = "Skill";
    player::resource = 5;
    player::armor = 12;
    player::weaponDmg = 55;
    player::money = 0;
    player::agility = 25;
}