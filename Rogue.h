//
// Created by BE123 on 5/1/2019.
//

#ifndef CIT66FINALPROJ_ROGUE_H
#define CIT66FINALPROJ_ROGUE_H


#include "player.h"

class Rogue : public player {
    //player class
private:
    string name = "Hugo";
    string weapon = "Sword";
    double health = 380;
    string resourceName = "Faith";
    int resource = 2;
    int armor = 45;
    double weaponDmg = 16;


};


#endif //CIT66FINALPROJ_ROGUE_H
