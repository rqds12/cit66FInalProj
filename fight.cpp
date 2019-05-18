//
// Created by sethsan on 5/2/19.
//

#include <iostream>
#include <string>
#include "fight.h"
#include "Orcs.h"
#include "player.h"
#include "Enemy.h"
#include "Medicine.h"
#include "Joseph_Stalin.h"
#include "Salem_Darkmore.h"
#include <random>
#include <ctime>
fight::fight() {
    prompt = "fight";
}

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

                bool stoppo = false;
                int a = 0;
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
                switch (a) {
                    case 1: {
                        (player1->attack(player2));
                    }
                        break;
                    case 2: {
                        ((player1)->specialAbility(player2));
                        }


                        break;
                    case 3: {
                        useItem(player1);
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
    this->action(player1, false);
    return false;
}
bool fight::action(player *player1, bool isboss) {

    player* player2;
    bool a = false;

    if (!isboss) {
            player2 = new Orcs;
            std::cout << "You encountered an Orc\n";
            if (player1->getAgility() >= player2->getAgility()){
                a= fightMenu(player1, player2, isboss);
                delete player2;
            }else{
                std::cout << "You were ambushed by an Orc, it attacks first\n";
                a=fightMenu(player2, player1, isboss);
                delete player2;
        }
    }else{

       std::random_device generator;
        std::uniform_real_distribution<double> distribution(0.5,1.5);


        if( distribution(generator) >  1){
            std::string color = "";
            std::uniform_int_distribution<int> distribution1(0,5);

           player2 = new Joseph_Stalin;
        }else{
            player2 = new Salem_Darkmore;
        }
        std::cout << "You encountered " << player2->getName() << ".\n"
                                                                 "You attack first\n";
        fightMenu(player1, player2, true);
    }
    return a;
}

int desicsionMaker(player* player1, player* player2, bool isBoss){

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0,100);


    if(!isBoss){
        player1->attack(player2);
        return 1;
    }else if(distribution(generator) >= 60 && (player1->getResource() >= player1->getResourceReq())){
        player1->specialAbility(player2);
        return 2;
    }else{
        player1->attack(player2);
        return 1;
    }
}

bool useItem(player *player1) {
    std::string choik;
    int a =0;

    if (!player1->getBag().empty()) {
        for (int i = 0; i < player1->getBag().size(); ++i) {
            std::cout << player1->getBag()[i]->getName() << std::endl;
        }
        bool stoppo = false;
        while (!stoppo) {
            try {
                getline(std::cin, choik);
                a = std::stoi(choik);
                if (a  > (player1->getBag().size()) && a==0) {
                    throw "hooligan";
                } else {
                    stoppo = true;
                }
            }
            catch (...) {
                cout << "Enter a valid number choice" << endl;
            }

        }
        Items *temp;
        temp = (player1->getBag()[a-1]);

        player1->usePotion((dynamic_cast<Medicine *>(temp)), a-1);


    }else{
        std::cout << "You do not have any items in your bag\n";
    }
    player1->displayStatus();
    return true;


}
