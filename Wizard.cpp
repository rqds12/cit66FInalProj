//
// Created by Seth on 5/1/2019.
//

#include "Wizard.h"

Wizard::Wizard(string &name) {
    player::name = name;
    player::weapon = "Not the elder wand, but kinda scary still...";
    player::health = 159;
    player::resourceName = "Mana";
    player::resource = 40;
    player::armor =3;
    player::weaponType = "Wand, Dragon Heartstring, 10 &3/4 inches";
    player::weaponDmg = 2.332;
}

bool Wizard::specialAbility()   {

}
