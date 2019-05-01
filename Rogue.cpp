//
// Created by BE123 on 5/1/2019.
//

#include "Rogue.h"
#include "Enemy.h"
#include <ctime>
Rogue::Rogue(string& name) {
    player::name = name;
    player::weapon = "Knife";
    player::health = 150;
    player::resourceName = "Anger";
    player::resource = 0;
    player::armor =25;
    player::weaponDmg = 34;
}

bool Rogue::specialAbility(Enemy& target) {
    srand(time(NULL));

    double chance = ((rand()% 10)+1)/10;
    if(chance >=0.4 && chance <= 0.6){
        target.setPoisoned(true);

        target.takeDamage(target.getHealth()-(target.getHealth()*chance), true);
    }

}