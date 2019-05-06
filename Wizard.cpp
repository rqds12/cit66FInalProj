//
// Created by Seth on 5/1/2019.
//

#include <iostream>
#include "Wizard.h"

Wizard::Wizard(std::string &name) {
    player::name = name;
    player::weapon = "The Elder Wand";
    player::health = 159;
    player::resourceName = "Mana";
    player::resource = 40;
    player::armor =3;
    player::weaponType = "Wand, Dragon Heartstring, 10 &3/4 inches";
    player::weaponDmg = 2.332;
    player::type = "Wizard";

}

bool Wizard::specialAbility(player target)   {
    if (resource >= 45){
        srand(time(0));
        int chance = rand() % 65;
        double dmg = 55 + chance;
        cout << this->getName() << " incants while reading from an ancient text with" << this->getWeapon() << ". He propels a bolt of the purest energy into his opponent."
                                                                       "\n" << target.getName() << " is struck down by a flowing, seething flow of power."<<endl;
        return target.takeDamage(dmg,false);

    }
    else{
        cout << getName() << " doesn't have enough " << getResourceName() << "to invoke the light of god.\n" << getName() << " looses most of their faith in their deity because of this failure" << endl;
        setResource((getResource())-(getResource())*0.85);
        setHealth(getHealth()*0.4);
        return false;
    }

}

bool Wizard::read() {
    std::string temp;
    reader.open("../WizardStory.txt");
    if (reader.is_open()) {
        while(reader.good()) {

            getline(reader, temp, '|');
            storyLine.push_back(temp);
            if(reader.bad()){
                return false;
            }
            return true;
        }
    }
}
