//
// Created by Erik on 5/1/2019.
//

#include <iostream>
#include "Paladin.h"
#include <string>

Paladin::Paladin(const std::string &name) {
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
        return target.takeDamage(dmg,false);

    }
    else{
        cout << getName() << " doesn't have enough " << getResourceName() << "to invoke the light of god.\n" << getName() << " looses most of their faith in their deity because of this failure" << endl;
        setResource((getResource())-(getResource())*0.85);
        setHealth(getHealth()*0.4)
        return false;
    }

}
