//
// Created by BE123 on 5/1/2019.
//

#ifndef CIT66FINALPROJ_ENEMY_H
#define CIT66FINALPROJ_ENEMY_H

#include <string>
#include "player.h"

using namespace std;
class Enemy: public player {
private:
    string name;
    string weapon;
    double health;
    string resourceName;
    int resource;
    int armor;
    double weaponDmg;
public:
    Enemy(string name);
};


#endif //CIT66FINALPROJ_ENEMY_H
