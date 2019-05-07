//
// Created by Erik on 5/1/2019.
//

#include <iostream>
#include "Paladin.h"
#include <string>
#include <fstream>

Paladin::Paladin(string &name) {
    player::name = name;
    player::type = "Paladin";
    player::weapon = "Abaddon's Exterminant";
    player::weaponType = "Two Handed Great Sword";
    player::health = 350;
    player::resourceName = "Faith";
    player::resource = 5;
    player::armor = 40;
    player::weaponDmg = 16;
    player::money = 0;
}

bool Paladin::specialAbility(player *target) {
    srand(time(NULL));
    cout << "\n Pick a Special Ability: \n"
            "1) ATERK\n"
            "2) Cast a Shield" << endl;
    std::string choiNum;
    getline(std::cin, choiNum);
    switch (stoi(choiNum)){
        case 1:{
            if (resource >= 60){
                int chance = rand() % 35;
                double dmg = 55 + chance;
                cout << this->getName() << " thrusts " << this->getWeapon() << "into the earth before him, ripping a void in the celestial fabric we exist upon."
                                                                               "\nSt.John sees his plight and advises his master of " << target->getName() << "'s sin. The glory of " << this->getName() <<"'s divine master purifies his opponent."<<endl;
                return target->takeDamage(dmg,false);
            }
            else{
                cout << getName() << " doesn't have enough " << this->getResourceName() << "to invoke the light of god.\n" << this->getName() << " looses most of their faith in their deity because of this failure" << endl;
                setResource((getResource())-(getResource())*0.85);
                setHealth(getHealth()*0.74);
                return false;
            }
        }
        case 2:{
            if (resource >= 100){
                int chance = rand() % 2000;
                setArmor(getArmor()+chance+5);
                cout << "St. George bathes you in the holy light, it protects you from your opponent's attack" << endl;
            }
        }
    }

}


bool Paladin::read() {
    std::string temp;
    reader.open("../PaladinStory.txt");
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

bool Paladin::takeDamage(double dmg, bool ispoison) {
    double rage = (dmg * 1.256);
    (ispoison) ? rage*3 : rage*2;
    this->setResource(rage);
    return player::takeDamage(dmg, ispoison);
}
/*
bool Paladin::write() {

}*/