//
// Created by sethsan on 5/2/19.
//

#include <iostream>
#include "fight.h"
#include "Orcs.h"
#include "player.h"
#include "Enemy.h"
bool fightMenu(player *player1, player* player2){


    while(player1->getHealth()>0 && player2->getHealth()){

    }
    return true;
}
bool fight::action(player *player1, bool isboss) {
    player* player2 = new Orcs;
    bool a = false;

    if (!isboss) {


            std::cout << "You encountered an Orc\n";
            if (player1->getAgility() >= player2->getAgility()){
                a= fightMenu(player1, player2);
                delete player2;
            }else{
                std::cout << "You were ambushed by an Orc, it attacks first\n";
                a=fightMenu(player2, player1);
                delete player2;
        }
    }
    return a;
}
