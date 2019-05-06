//
// Created by BE123 on 5/1/2019.
//

#ifndef CIT66FINALPROJ_ROGUE_H
#define CIT66FINALPROJ_ROGUE_H


#include "player.h"
#include "Enemy.h"

class Rogue : public player {
    //player class
public:
    explicit Rogue(string &name);
    bool specialAbility(Enemy& target);
    bool takeDamage(double dmg,bool ispoison);
    bool read();



};


#endif //CIT66FINALPROJ_ROGUE_H
