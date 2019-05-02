//
// Created by sethsan on 4/30/19.
//

#include <iostream>
#include "player.h"
#include <cstdlib>
#include <ctime>

void player::displayStatus() {

}

bool player::attack(player target) {
    int toHitRoll = rand() % 100;
    if (toHitRoll > target.getAgility()){
        // Attack is Dodged
        std::cout << name << " attacks " << target.getName() << " with their "<< weapon << ", but " << target.getName() <<
          " artfully dodges "<< "the attack causing embarrassment for " << name << ".\n\n";
        return false;
    }
    // Attack Succeeds
    double dmg = (rand() % 15) + weaponDmg;
    std::cout << name << " attacks " << target.getName() << " with their "<< weapon << " and delivers a destructive blow causing " << dmg<< " points of damage.\n\n";
    return target.takeDamage(dmg,false);
}

bool player::takeDamage(double dmg,bool ispoison) {
    //checks if the attack poisons
    if (!ispoison) {
        if (armor > 0) {
            std::cout << name << "'s armor blocks " << armor << " points of the incoming " << "damage.\n\n";
            dmg -= armor;
            armor -= (dmg * 0.70);
        }
    }
    //poison decrementor
    if (poisoned){
        health -=dmg + (--popo);
    }
    else {
        health -= dmg;
    }
    //death msg
    if (health <= 0){cout << name << " breathes their last breath while cursing the bane for failing their path. "<<
     " It is truly a dark day for the empire...\n\n"<< name << " has died.\n\n";
    return true;
    }
    return false;
}

bool player::specialAbility(player target, int choiNum) {
    return false;
}

const std::string &player::getName() const {
    return name;
}
void player::setName(const std::string &name) {
    player::name = name;
}
const std::string &player::getWeapon() const {
    return weapon;
}
void player::setWeapon(const std::string &weapon) {
    player::weapon = weapon;
}
double player::getHealth() const {
    return health;
}
void player::setHealth(double health) {
    player::health = health;
}
const std::string &player::getResourceName() const {
    return resourceName;
}
void player::setResourceName(const std::string &resourceName) {
    player::resourceName = resourceName;
}
double player::getResource() const {
    return resource;
}
void player::setResource(double resource) {
    player::resource = resource;
}
double player::getArmor() {
    return armor;
}
void player::setArmor(double armor) {
    player::armor = armor;
}
double player::getWeaponDmg() const {
    return weaponDmg;
}
void player::setWeaponDmg(double weaponDmg) {
    player::weaponDmg = weaponDmg;
}
int player::getAgility() const {
    return agility;
}
void player::setAgility(int agility) {
    player::agility = agility;
}
bool player::isPoisoned() const {
    return poisoned;
}
void player::setPoisoned(bool poisoned) {
    player::poisoned = poisoned;
}

bool player::usePotion(Medicine medicine) {
    if(this->isPoisoned()&&medicine.isCurePoison()){
        poisoned = false;
    }
    player::health += medicine.getHealingPower();

    return false;
}

const std::vector<std::string> &player::getStoryLine() const {
    return storyLine;
}

void player::setStoryLine(const std::vector<std::string> &storyLine) {
    player::storyLine = storyLine;
}

bool player::read() {
    return false;
}

const string &player::getWeaponType() const {
    return weaponType;
}

void player::setWeaponType(const string &weaponType) {
    player::weaponType = weaponType;
}

double player::getMoney() const {
    return money;
}

void player::setMoney(double money) {
    player::money = money;
}

void player::shop(player recipient) {
    int a = 0;
    cout << "=============================" << endl;
    cout << "==Welcome to Ye Olde Shoppe==" << endl;
    cout << "=============================" << endl;
    cout << "=============================" << endl;
    cout << "Welcome " << recipient.getName() << ", you have " << recipient.getMoney() << " gold to spend...\n" << endl;

    cout << "1) Medicinal Herbs (+25 health)............8 gold\n"
            "2) "<< recipient.getWeaponType() << " Sharpening/Reforging by the local Armorer (+5 Damage)............14 gold\n"
            "3) Leather Breastplate (+6 Armor)............6 gold\n"
            "4) Iron Breastplate (+8 Armor)............8 gold\n"
            "5) A good kick in the pants (-2 health)............1 gold\n"
            "6) Short Sword, good for blocking and knifing political opponents in the back (+13 Damage)............30 gold" << endl << endl;
    //todo: make poison thingamagig
    cout << "Enter your selection: " << endl;
    cin >> a;
    switch (a) {
        case 1: {
            //todo:fix protected
        recipient.bag.push_back(Medicine("Weed",25))
        }
        case 2: {
            recipient.setWeaponDmg(recipient.getWeaponDmg()+5);
        }
        case 3:{
            recipient.setArmor(recipient.getArmor()+6);
        }
        case 4:{
            recipient.setArmor(recipient.getArmor()+8);
        }
        case 5:{
            recipient.setHealth(recipient.getHealth()-2);
        }
        case 6:{
            recipient.setWeaponDmg(recipient.getWeaponDmg()+13);
        }
    }



}

