//
// Created by Erik on 5/1/2019.
//

#include <iostream>
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
        srand(time(0));
        int chance = rand() % 35;
        double dmg = 55 + chance;
        return target.takeDamage(dmg);
    }
    else{
        cout << getName() << " doesn't have enough " << getResourceName() << "to invoke the light of god. " << getName() << "looses most of their faith in their deity because of this failure" << endl;
        setResource((getResource())-(getResource())*0.6);
        return false;
    }

}
