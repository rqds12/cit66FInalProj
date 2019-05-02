//
// Created by Erik on 5/1/2019.
//

#include <iostream>
#include "Paladin.h"
#include <string>
#include <fstream>

Paladin::Paladin(string &name) {
    player::name = name;
    player::weapon = "Abaddon's Exterminant";
    player::weaponType = "Two Handed Great Sword";
    player::health = 350;
    string resourceName = "Faith";
    player::resource = 5;
    player::armor = 40;
    player::weaponDmg = 16;
    player::money = 0;
}

bool Paladin::specialAbility(player target) {
    if (resource >= 60){
        srand(time(0));
        int chance = rand() % 35;
        double dmg = 55 + chance;
        cout << this->getName() << " thrusts " << this->getWeapon() << "into the earth before him, ripping a void in the celestial fabric we exist upon."
                "\nSt.John sees his plight and advises his master of " << target.getName() << "'s sin. The glory of " << this->getName() <<"'s devine master purifys his opponent."<<endl;
        return target.takeDamage(dmg,false);

    }
    else{
        cout << getName() << " doesn't have enough " << getResourceName() << "to invoke the light of god.\n" << getName() << " looses most of their faith in their deity because of this failure" << endl;
        setResource((getResource())-(getResource())*0.85);
        setHealth(getHealth()*0.4);
        return false;
    }

}

bool Paladin::read() {
    std::string temp;
    reader.open("PaladinStory");
    if (reader.is_open()) {
        while(reader.good()) {

                getline(reader, temp, '|');
                storyLine.push_back(temp);
                if(reader.bad()){
                    break;
            ;
            }
        }
    }
    return true;
}
/*
bool Paladin::write() {

}*/