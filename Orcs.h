//
// Created by Seth on 5/2/19.
//

#ifndef CIT66FINALPROJ_ORCS_H
#define CIT66FINALPROJ_ORCS_H


#include "Enemy.h"

class Orcs: public Enemy {
protected:
    //bool isOrc;
public:
    bool specialAbility = 0;
    Orcs();
    void setResource(double resource);

};


#endif //CIT66FINALPROJ_ORCS_H
