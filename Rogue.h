//
// Created by BE123 on 5/1/2019.
//

#ifndef CIT66FINALPROJ_ROGUE_H
#define CIT66FINALPROJ_ROGUE_H


#include "player.h"

class Rogue : public player {
    //player class
public:
    explicit Rogue(string &name);
    bool specialAbility(player target);



};


#endif //CIT66FINALPROJ_ROGUE_H
