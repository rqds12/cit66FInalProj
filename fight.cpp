//
// Created by sethsan on 5/2/19.
//

#include <iostream>
#include "fight.h"
#include "Orcs.h"
#include "player.h"
#include "Enemy.h"
#include "Medicine.h"
bool fightMenu(player *player1, player* player2, bool isBoss){
    if((player1->getisEnemy() && !player2->getisEnemy()) || (!player1->getisEnemy() && player2->getisEnemy())) {
        //one is an enemy and one is a player
        while (player1->getHealth() > 0 && player2->getHealth() > 0) {


            if (player1->getisEnemy()) {
                desicsionMaker(player1, player2, isBoss);

                std::swap(player1, player2);

            } else {
                string choik = "";
                bool kill = false;
                player1->fightDisplay();
                player2->fightDisplay();
                cout << player1->getName() << "'s turn!!\n"
                                              "Choose a move:\n"
                                              "1) Attack\n"
                                              "2) Special Move(s)\n"
                                              "3) Use Item"<< endl;

              // getline(std::cin, choik); //todo: add in try catch blocks
              std::cin >> choik;

                switch (std::stoi(choik)) {
                    case 1: {
                        (player1->attack(player2));
                    }
                        break;
                    case 2: {
                        ((player1)->specialAbility(player2));

                    }
                    case 3:{
                        for (int i = 0; i < player1->getBag().size()  ; ++i) {
                            std::cout << player1->getBag()[i].getName() << std::endl;
                        }
                        getline(std::cin, choik);
                        Items *temp;
                        *temp = (player1->getBag()[std::stoi(choik)-1]);

                        player1->usePotion(*(dynamic_cast<Medicine*>(temp)));
                    }
                }
                std::swap(player1, player2);
            }
        }

    }else if(!player1->getisEnemy() && !player2->getisEnemy()){
        //both are players
        string choik;
        bool kill = false;
        int a = 0;
        while ((player1->getHealth() > 0 && player2->getHealth() > 0)&&(!kill)){
           std::swap(player1, player2);
            player1->fightDisplay();
            player2->fightDisplay();
           cout << player1->getName() <<"'s turn!!\n"
                                         "Choose a move:\n"
                                         "1) Attack\n"
                                         "2) Special Move(s)\n"
                                         "3) Shop" <<endl;
            bool stoppo = false;
            while (!stoppo) {
                try {
                    getline(std::cin, choik);
                    a = std::stoi(choik);
                    if (a != 1 && a != 2 && a!=3) {
                        throw "hooligan";
                    } else {
                        stoppo = true;
                    }
                }
                catch (...) {
                    cout << "Enter a choice, 1 or 2 or 3" << endl;
                }

            }
            switch (a){
                case 1:{
                    kill = (player1->attack(player2));
                }
                break;
                case 2:{
                    kill = ((player1)->specialAbility(player2));
                }
                break;
                case 3:{
                    player1->shop();
                }
                break;
            }
        }
    }else{
        //both are enemy
    }
    return true;
}
bool fight::action(player *player1) {
    this->action(player1, 0);
    return false;
}
bool fight::action(player *player1, bool isboss) {
    player* player2 = new Orcs;
    bool a = false;

    if (!isboss) {


            std::cout << "You encountered an Orc\n";
            if (player1->getAgility() >= player2->getAgility()){
                a= fightMenu(player1, player2, isboss);
                delete player2;
            }else{
                std::cout << "You were ambushed by an Orc, it attacks first\n";
                a=fightMenu(player2, player1, isboss);
                delete player2;
        }
    }
    return a;
}

int desicsionMaker(player* player1, player* player2, bool isBoss){
    if(!isBoss){
        player1->attack(player2);
        return 1;
    }else if(player1->getResource() >= player1->getResourceReq()){
        player1->specialAbility(player2);
        return 2;
    }else{
        player1->attack(player2);
        return 1;
    }
}