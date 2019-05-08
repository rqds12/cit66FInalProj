//
// Created by sethsan on 5/2/19.
//

#include <iostream>
#include "fight.h"
#include "Orcs.h"
#include "player.h"
#include "Enemy.h"
bool fightMenu(player *player1, player* player2){
    if((player1->getisEnemy() && !player2->getisEnemy()) || (!player1->getisEnemy() && player2->getisEnemy())) {
        //one is an enemy and one is a player
        while (player1->getHealth() > 0 && player2->getHealth() > 0) {


            if (player1->getisEnemy()) {

            }else{

            }
        }

    }else if(!player1->getisEnemy() && !player2->getisEnemy()){
        //both are players
        string choik;
        bool kill = false;
        while ((player1->getHealth() > 0 && player2->getHealth() > 0)||(kill)){
            std::swap(player1, player2);
            cout << player1->getName() <<"'s turn!!\n"
                                         "Choose a move:\n"
                                         "1) Attack\n"
                                         "2) Special Move(s)\n"
                                         "3) Shop" <<endl;
            getline(std::cin,choik);
            switch (stoi(choik)){
                case 1:{
                    (player1->attack(player2)) ? kill = true : kill = false;
                }
                break;
                case 2:{
                    ((player1)->specialAbility(player2)) ? kill = true : kill = false;
                }
            }
        }
    }else{
        //both are enemy
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

//int desicsionMaker(player* player1, player* player2){
//
//}