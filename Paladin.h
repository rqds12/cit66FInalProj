//
// Created by erik on 5/1/2019.
//

#ifndef CIT66FINALPROJ_PALADIN_H
#define CIT66FINALPROJ_PALADIN_H


#include "player.h"
#include "Enemy.h"

class Paladin : public player {
    //player class

public:
    bool specialAbility(player *target) override;
    Paladin(string &name);
    bool takeDamage(double dmg,bool ispoison) override;
    bool read() override;


};


#endif //CIT66FINALPROJ_PALADIN_H
