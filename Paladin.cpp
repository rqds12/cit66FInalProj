//
// Created by Erik on 5/1/2019.
//

#include <iostream>
#include "Paladin.h"
#include <string>
#include <fstream>
#include <random>
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
    player::agility = 8;
}

bool Paladin::specialAbility(player *target) {
   std::random_device generator;
   std::uniform_int_distribution<int> distribution(0,35);
   std::uniform_int_distribution<int> distribution1(0,2000);
    cout << "\n Pick a Special Ability: \n"
            "1) ATERK\n"
            "2) Cast a Shield" << endl;
    std::string choiNum;
    bool stoppo = false;
    int a = 0;
    while (!stoppo) {
        try {
            getline(std::cin, choiNum);
            a = std::stoi(choiNum);
            if (a != 1 && a != 2) {
                throw "hooligan";
            } else {
                stoppo = true;
            }
        }
        catch (...) {
            cout << "Enter a choice, 1 or 2" << endl;
        }

    }
    switch (a){
        case 1:{
            if (resource >= 60){
                int chance = distribution(generator);
                double dmg = 55 + chance;
                cout << this->getName() << " thrusts " << this->getWeapon() << " into the earth before him, ripping a void in the celestial fabric we exist upon."
                                                                               "\nSt.John sees his plight and advises his master of " << target->getName() << "'s sin. The glory of " << this->getName() <<"'s divine master purifies " << dmg <<" from his opponent."<<endl;
                setResource(getResource()-getResourceReq());
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
                int chance = distribution1(generator);
                setArmor(getArmor()+chance+5);
                cout << "St. George bathes you in the holy light, it protects you from your opponent's attack" << endl;
                return false;
            }
        }
    }
return false;
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

            }
        }
    }
    return true;
}

bool Paladin::takeDamage(double dmg, bool ispoison) {
    double rage = (dmg * 1.256);
    (ispoison) ? rage*3 : rage*2;
    this->setResource(this->getResource()+rage);
    return player::takeDamage(dmg, ispoison);
}
/*
bool Paladin::write() {

}*/