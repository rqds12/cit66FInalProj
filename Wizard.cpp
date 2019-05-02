//
// Created by Seth on 5/1/2019.
//

#include "Wizard.h"

Wizard::Wizard(std::string &name) {
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
bool Wizard::read() {
    std::string temp;
    reader.open("PaladinStory");
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
}
