//
// Created by sethsan on 4/30/19.
//

#ifndef CIT66FINALPROJ_PLAYER_H
#define CIT66FINALPROJ_PLAYER_H


#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Items.h"
#include "Medicine.h"

using namespace std;
class player {
        protected:
        string name;
        string weapon;
        double health;
        string resourceName;
        double resource;
        double armor;
        double weaponDmg;
        int agility;
        bool poisoned = false;
        int popo = 4;
        vector <Items> bag;

public:
    void displayStatus();
    bool attack(player target);
    bool takeDamage(double dmg, bool ispoison);
    virtual bool specialAbility(player target);

    const string &getName() const;
    void setName(const string &name);
    const string &getWeapon() const;
    void setWeapon(const string &weapon);
    double getHealth() const;
    void setHealth(double health);
    const string &getResourceName() const;
    void setResourceName(const string &resourceName);
    double getResource() const;
    void setResource(double resource);
    double getArmor();
    void setArmor(double armor);
    double getWeaponDmg() const;
    void setWeaponDmg(double weaponDmg);
    int getAgility() const;
    void setAgility(int agility);
    bool isPoisoned() const;
    void setPoisoned(bool poisoned);
    bool usePotion(Medicine medicine);


};


#endif //CIT66FINALPROJ_PLAYER_H
