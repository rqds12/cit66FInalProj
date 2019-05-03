//
// Created by sethsan on 4/30/19.
//

#include <iostream>
#include "player.h"
#include <cstdlib>
#include <ctime>

void player::displayStatus() {
    cout << endl << endl << endl << endl << endl;
    cout << "Name: " << this->getName() << "\n"
            "Class: " << this->getType() << "\n"
            "Weapon: " <<this->getWeapon() << "\n"
            "Weapon Type: " << this->getWeaponType() << "\n"
            "Health: " << this->getHealth() << "\n"
             "Money: " << this->getMoney() << "\n"
             "Armor: " << this->getArmor() << "\n"
             << this->getResourceName() << ": " << this->getResource() << endl <<endl;

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
const string &player::getType() const {
    return type;
}
void player::setType(const string &type) {
    player::type = type;
}

bool player::usePotion(const Medicine medicine) {
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


void player::shop() {
    bool yeetusDeletus = false;
    while (!yeetusDeletus) {
        int a = 0;
        cout << "=============================" << endl;
        cout << "==Welcome to Ye Olde Shoppe==" << endl;
        cout << "=============================" << endl;
        cout << "=============================" << endl;
        cout << "Welcome " << this->getName() << ", you have " << this->getMoney() << " gold to spend...\n"
             << endl;

        cout << "1) Medicinal Herbs (+25 health)............8 gold\n"
                "2) " << getWeaponType()
             << " Sharpening/Reforging by the local Armorer (+5 Damage)............14 gold\n"
                "3) Leather Breastplate (+6 Armor)............6 gold\n"
                "4) Iron Breastplate (+8 Armor)............8 gold\n"
                "5) A good kick in the pants (-2 health)............1 gold\n"
                "6) Short Sword, good for blocking and knifing political opponents in the back (+17 Damage)............30 gold"
             << endl << endl;
        //todo: make poison thingamagig
        cout << "Enter your selection: " << endl;
        cin >> a;
        switch (a) {
            case 1: {
                if (this->getMoney()>=8){
                    this->bag.push_back(Medicine("Medicinal Herbs", 25));
                    this->setMoney(this->getMoney()-8);
                }
                else{
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16,false);
                }
            }
            break;

            case 2: {
                if (this->getMoney()>=14) {
                    this->setWeaponDmg(this->getWeaponDmg() + 5);
                    this->setMoney(this->getMoney()-14);
                }
                else{
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16,false);
                }
            }
                break;
            case 3: {
                if (this->getMoney() >= 6) {
                    this->setArmor(this->getArmor() + 6);
                    this->setMoney(this->getMoney()-6);
                }
                else {
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16, false);
                }
            }
                break;
            case 4: {
                if (this->getMoney()>= 8){
                    this->setArmor(this->getArmor() + 8);
                    this->setMoney(this->getMoney()-8);
                }
                else{
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16,false);
                }
            }
                break;
            case 5: {
                if (this->getMoney()>=1){
                    this->setHealth(this->getHealth() - 2);
                    this->setMoney(this->getMoney()-1);
                }
                else{
                    cout << "You obviously need this gold more than I do... By the way, here is a sword and some weed" << endl;
                    this->setWeaponDmg(this->getWeaponDmg()+17);
                    this->setMoney(this->getMoney()+12);
                    this->bag.push_back(Medicine("Herbs ;)",25));
                }
            }
                break;
            case 6: {
                if (this->getMoney()>= 30){
                    this->setWeaponDmg(this->getWeaponDmg() + 17);
                    this->setMoney(this->getMoney()-30);
                }
                else{
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16,false);
                }
            }
                break;
            case 7: {
                yeetusDeletus = true;
            }
            default:{
                    cout << "Shop owner beats you severely with a cricket bat for being a hooligan" << endl;
                this->takeDamage(35,false);

            }
        }


    }
}




