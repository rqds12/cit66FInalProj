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

    return false;
}

bool player::takeDamage(int dmg) {
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
int player::getResource() const {
    return resource;
}
void player::setResource(int resource) {
    player::resource = resource;
}
int player::getArmor() const {
    return armor;
}
void player::setArmor(int armor) {
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
