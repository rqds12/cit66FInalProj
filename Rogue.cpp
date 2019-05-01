//
// Created by BE123 on 5/1/2019.
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
    if()
}