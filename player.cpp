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
        cout << name << " attacks " << target.getName() << " with their "<< weapon << ", but " << target.getName() <<
          " artfully dodges "<< "the attack causing embarrassment for " << name << ".\n\n";
        return false;
    }
    // Attack Succeeds
    double dmg = (rand() % 15) + weaponDmg;
    cout << name << " attacks " << target.getName() << " with their "<< weapon << " and delivers a destructive blow causing " << dmg<< " points of damage.\n\n";
    return target.takeDamage(dmg,false);
}

bool player::takeDamage(double dmg,bool ispoison) {
    if (!ispoison) {
        if (armor > 0) {
            cout << name << "'s armor blocks " << armor << " points of the incoming " << "damage.\n\n";
            dmg -= armor;
            armor -= (dmg * 0.70);
        }
    }
    if (poisoned){
        health -=dmg + (--popo);
    }
    else {
        health -= dmg;
    }
    if (health <= 0){cout << name << " breathes their last breath while cursing the gods "<<
     "that brought about such a cruel world and such suffering.\n\n"<< name << " has died.\n\n";
    return true;
    }
    return false;
}

bool player::specialAbility(player target) {
    return false;
}

const string &player::getName() const {
    return name;
}
void player::setName(const string &name) {
    player::name = name;
}
const string &player::getWeapon() const {
    return weapon;
}
void player::setWeapon(const string &weapon) {
    player::weapon = weapon;
}
double player::getHealth() const {
    return health;
}
void player::setHealth(double health) {
    player::health = health;
}
const string &player::getResourceName() const {
    return resourceName;
}
void player::setResourceName(const string &resourceName) {
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

