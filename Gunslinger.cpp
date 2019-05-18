//
// Created by sethsan on 5/13/19.
//

#include <iostream>
#include "Gunslinger.h"
bool Gunslinger::specialAbility(player *target) {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0,55);
    std::string choiNum;
    int a = 0;
    cout << "\n Pick a Special Ability: \n"
            "1) ATERK\n"
            "2) Heal yourself" << endl;

    bool stoppo = false;
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
            if (resource >= 20 && !dodge(target)){
                int chance = distribution(generator);
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
        case 2:{
            cout << "\nSteadying yourself and aiming to fire next time.." <<endl;
            setAgility(getAgility()+5);
            setWeaponDmg(getWeaponDmg()+25);
            return false;
        }
    }
    return false;

}

bool Gunslinger::takeDamage(double dmg, bool ispoison) {
    double rage = (dmg * 1.256);
    (ispoison) ? rage*-0.22 : rage*2;
    this->setResource(this->getResource()+rage);
    return player::takeDamage(dmg, ispoison);
}

bool Gunslinger::read() {
    std::string temp;
    reader.open("../Gunslinger.txt");
    if(reader.is_open()){
        while(reader.good()){
            getline(reader, temp, '|');
            storyLine.push_back(temp);
            if(reader.bad()){
                break;
            }
        }
    }
    return true;
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
    player::agility = 55;
}