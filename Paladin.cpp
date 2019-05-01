//
// Created by Erik on 5/1/2019.
//

#include "Paladin.h"

Paladin::Paladin(string &name) {
    player::name = name;
    player::weapon = "Sword of God";
    player::health = 350;
    string resourceName = "Faith";
    player::resource = 5;
    player::armor = 40;
    player::weaponDmg = 16;
}

bool Paladin::specialAbility(player target) {
    if (resource >= 60){

    }
    return player::takeDamage(dmg);
}
