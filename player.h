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
#include <fstream>
#include "Problem.h"

class Items;
class Medicine;
class Problem;

using namespace std;
class player {
protected:
        std::string name;
        std::string weapon;
        double health;
       std::string resourceName;
        double resource;
        double resourceReq;
        double armor;
        double weaponDmg;
        string weaponType;
        int agility;
        bool poisoned = false;
        int popo = 4;
        std::vector<Items*> bag;
        std::ifstream reader;
        std::ofstream writer;
        std::vector<std::string> storyLine;
        double money;
        std::vector<Problem*>* problems;
        bool isEnemy =false;
        string type;

public:
    const string &getType() const;

    void setType(const string &type);


    void displayStatus();
    void fightDisplay();
    bool attack(player *target);
    virtual bool takeDamage(double dmg, bool ispoison);
    virtual bool specialAbility(player *target);
    void shop();
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getWeapon() const;
    void setWeapon(const std::string &weapon);
    double getHealth() const;
    void setHealth(double health);
    const std::string &getResourceName() const;
    void setResourceName(const std::string &resourceName);
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
    bool usePotion(Medicine* medicine, int a);
    virtual bool read();
    //virtual bool write();
    const std::vector<std::string> &getStoryLine() const;

    void setStoryLine(const std::vector<std::string> &storyLine);
    const string &getWeaponType() const;
    void setWeaponType(const string &weaponType);
    double getMoney() const;
    void setMoney(double money);

    bool getisEnemy() const;

    void setIsEnemy(bool isEnemy);

    double getResourceReq() const;

    void setResourceReq(double resourceReq);

    vector<Problem*> *getProblems() const;

    void setProblems(vector<Problem*> *problems);

    void createProblems(int n);

    const vector<Items *> &getBag() const;

    void setBag(const vector<Items *> &bag);
};





#endif //CIT66FINALPROJ_PLAYER_H
