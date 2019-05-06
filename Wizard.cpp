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

bool Wizard::specialAbility(player target, int choiNum)   {
    switch (choiNum){
        case 1:{
            srand(time(NULL));
            if (resource >= 45){
                srand(time(0));
                int chance = rand() % 25;
                double dmg = 15 + chance;
                cout << this->getName() << " incants while reading from an ancient text with" << this->getWeapon() << ". He propels a bolt of the purest energy into his opponent."
                                                                                                                      "\n" << target.getName() << " is struck down by a flowing, seething flow of power."<<endl;
                return target.takeDamage(dmg,false);

            }
            else{
                cout << getName() << " doesn't have enough " << getResourceName() << "to draw on dumbledore's secrets.\n" << getName() << " looses most of their mana because of this failure" << endl;
                setResource((getResource())-(getResource())*0.85);
                setHealth(getHealth()*0.95);
                return false;
            }
        }
        case 2:{
            if (resource >= 30){
                srand(time(0));
                int chance = rand() % 35;
                double healer = 10 + chance;
                cout << this->getName() << " uses a healing spell which replaces " << healer << " health." << endl;
            }
        }
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

bool Wizard::takeDamage(double dmg, bool ispoison) {
    double rage = (dmg * 0.256);
    (ispoison) ? rage*0.5 : rage*7;
    this->setResource(rage);
    return player::takeDamage(dmg, ispoison);
}
