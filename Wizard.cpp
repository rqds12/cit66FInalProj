//
// Created by BE123 on 5/1/2019.
//

#include "Wizard.h"

Wizard::Wizard(string &name) {
    player::name = name;
    player::weapon = "staff";
    player::health = 100;
    string resourceName;
    player::resource = 100;
    player::armor =100;
    player::weaponDmg =100;
}