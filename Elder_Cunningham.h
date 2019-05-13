//
// Created by sethsan on 5/1/19.
//

#ifndef CIT66FINALPROJ_ELDER_CUNNINGHAM_H
#define CIT66FINALPROJ_ELDER_CUNNINGHAM_H


#include "Enemy.h"

class Elder_Cunningham: public Enemy {
    bool specialAbility(player& target);

private:
    Elder_Cunningham();
};


#endif //CIT66FINALPROJ_ELDER_CUNNINGHAM_H
