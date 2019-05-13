//
// Created by sethsan on 5/1/19.
//

#ifndef CIT66FINALPROJ_INDIAN_POWER_RANGERS_H
#define CIT66FINALPROJ_INDIAN_POWER_RANGERS_H


#include "Enemy.h"

class Indian_Power_Rangers: public Enemy{
private:
    std::string color ="";
public:
    bool specialAbility(player* target);
    Indian_Power_Rangers(std::string color);

    const string &getColor() const;

    void setColor(const string &color);

};


#endif //CIT66FINALPROJ_INDIAN_POWER_RANGERS_H
