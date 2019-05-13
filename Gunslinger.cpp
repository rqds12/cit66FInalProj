//
// Created by sethsan on 5/13/19.
//

#include <iostream>
#include "Gunslinger.h"
bool Gunslinger::specialAbility(player *target) {
    srand(time(NULL));
            if (resource >= 20){
                int chance = rand() % 55;
                double dmg = 55 + chance;
                cout << this->getName() << " quick draws their " << this->getWeapon() << " and fires a single shot into the nearby propane tank."
                    "\nThe tank explodes and shrapnel hits " << target->getName() << ". "<< target->getName() <<" bleeds " << dmg <<" units of blood and he is weakened considerably"<<endl;
                return target->takeDamage(dmg,false);
            }
            else{
                cout << getName() << " doesn't have enough " << this->getResourceName() << " to quick draw with accuracy.\n" << this->getName() << " shoots themselves in the foot." << endl;
                setResource((getResource())-(getResource())*0.85);
                setHealth(getHealth()*0.74);
                setAgility(getAgility()*.355);
                return false;
                //todo: make take aim to fire special ability which costs no resource but costs turn
}
}

bool Gunslinger::takeDamage(double dmg, bool ispoison) {
    double rage = (dmg * 1.256);
    (ispoison) ? rage*-0.22 : rage*2;
    this->setResource(this->getResource()+rage);
    return player::takeDamage(dmg, ispoison);
}

bool Gunslinger::read() {
    return false;
}

Gunslinger::Gunslinger(string &name){
    player::name = name;
    player::type = "Gunslinger";
    player::weapon = "Bang Bang Shootem' up";
    player::weaponType = "6 Shooter";
    player::health = 25;
    player::resourceName = "Skill";
    player::resource = 5;
    player::armor = 12;
    player::weaponDmg = 55;
    player::money = 0;
    player::agility = 45;
}