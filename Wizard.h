//
// Created by Seth on 5/1/2019.
//

#ifndef CIT66FINALPROJ_WIZARD_H
#define CIT66FINALPROJ_WIZARD_H


#include "player.h"

class Wizard : public player {
    //player class
public:
    explicit Wizard(std::string &name);
    bool specialAbility(player target, int choiNum);
    bool read();
    bool takeDamage(double dmg,bool ispoison);


};


#endif //CIT66FINALPROJ_WIZARD_H
