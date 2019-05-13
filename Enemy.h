//
// Created by BE123 on 5/1/2019.
//

#ifndef CIT66FINALPROJ_ENEMY_H
#define CIT66FINALPROJ_ENEMY_H

#include <string>
#include "player.h"

using namespace std;
class Enemy: public player {
protected:

public:
    Enemy();

    virtual bool specialAbility(player* target) ;





};


#endif //CIT66FINALPROJ_ENEMY_H
