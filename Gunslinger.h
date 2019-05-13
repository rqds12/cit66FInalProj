//
// Created by sethsan on 5/13/19.
//

#ifndef CIT66FINALPROJ_GUNSLINGER_H
#define CIT66FINALPROJ_GUNSLINGER_H


#include "player.h"

class Gunslinger : public player{
public:
    bool specialAbility(player *target) override;
    Gunslinger (string &name);
    bool takeDamage(double dmg,bool ispoison) override;
    bool read() override;

};




#endif //CIT66FINALPROJ_GUNSLINGER_H
