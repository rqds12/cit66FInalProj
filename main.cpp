#include <iostream>
#include <string>
#include "Paladin.h"
#include "player.h"
#include "Wizard.h"
#include "Rogue.h"
#include "fight.h"
#include "Gunslinger.h"
void credits();
void play(std::vector <player*> players);
void startingMenu();
int main() {
    startingMenu();
    return 0;
}

void play(std::vector<player*> players){
    if (players.size()==2){
        player *player1 = (players[0]);
        player *player2 = (players[1]);
        player1->displayStatus();
        player2->displayStatus();
        fightMenu(player1,player2, false);
    }else {
        player *player1 = (players[0]);

        player1->displayStatus();
        player1->read();

        std::vector<std::string> story = player1->getStoryLine();
        for (int i = 0; i < story.size(); ++i) {
            char temp = (story[i])[0];
            (story[i]).erase((story[i].begin()));
            std::cout << story[i] << std::endl;
            if (temp != '%' && temp != '^' ){
                player1->createProblems(5);
                for (int j = 0; j < player1->getProblems()->size(); ++j) {

                    std::cout << "1) Continue on \n"
                                 "2) Use an Item\n"
                                 "3) Rest\n"
                                 "4) Save Game\n";
                    std::string choice = "";
                    //todo: implement a menu for continuing on or resting or using a potion
                    bool trial = true;
                    while(trial) {
                        try {
                            getline(std::cin, choice);
                            if (std::stoi(choice) != 1 && std::stoi(choice) != 2 && std::stoi(choice) != 3 &&
                                std::stoi(choice) != 4) {
                                throw "hooligan";
                            } else{
                                trial = false;
                            }
                        }
                        catch (...) {
                            std::cout << "Enter 1,2,3 or 4\n";
                        }

                    }
                    switch (std::stoi(choice)) {
                        case 1: {
                            (*player1->getProblems())[j]->action(player1);
                        }
                        break;
                        case 2:{
                            //todo: use an Item
                        }
                        break;
                        case 3:{
                            //todo: rest
                        }
                        break;
                        case 4:{
                            player1->write(i, j);
                            return;

                        }
                    }

                }
            }else if(temp == '%'){
                fight fight1;
                fight1.action(player1, true);
            }else if(  temp == '^' ){
               credits();
            }

        }
    }



}

void credits(){


}
void startingMenu() {
    std::vector<player *> players;
    std::string temp;
    bool yeetusDeletus = false;
    bool yeetus2Deletus = false;

    std::cout << "Welcome to Text Adventure 3000\n" <<
              "Please Select a mode: \n"
              "1) Story Mode\n"
              "2) 2 Player\n"
              "3) load from a previous file\n";
    int a = 1;
    int b = 0;
    int c =0;
    while (!yeetus2Deletus) {
        try {
            getline(std::cin, temp);
            a = std::stoi(temp);
            if (a != 1 && a != 2 && a != 3) {
                throw "hooligan";
            } else if(a != 1 && a != 2){
                yeetus2Deletus = true;
                a = 1;
                c = 1;
            }else{
                yeetus2Deletus = true;

            }
        }
        catch (...) {
            cout << "Enter a choice, 1 or 2" << endl;
        }

    }

    if(c == 1){
        auto user1 = setRead();
        players.push_back(user1);
    }else {
        for (int i = 0; i < a; ++i) {
            yeetusDeletus = false;
            int ii = i + 1;
            cout << "Please Select a class for player " << ii << ": \n" <<
                 "1) Paladin\n" <<
                 "2) Wizard\n" <<
                 "3) Rogue\n" <<
                 "4) Gunslinger" << endl;

            while (yeetus2Deletus) {
                try {
                    getline(std::cin, temp);
                    b = std::stoi(temp);
                    if (b != 1 && b != 2 && b != 3 && b != 4) {
                        throw "hooligan";
                    } else {
                        yeetus2Deletus = false;
                    }
                }
                catch (...) {
                    cout << "Enter a choice, 1 or 2 or 3 or 4" << endl;
                }
            }
            yeetus2Deletus = true;

            while (!yeetusDeletus) {
                switch (b) {
                    case 1: {
                        std::cout << "Enter your name, young Paladin\n";
                        getline(std::cin, temp);

                        auto user1 = new Paladin(temp);
                        players.push_back(user1);
                        yeetusDeletus = true;
                    }
                        break;
                    case 2: {
                        std::cout << "Enter your name, young Wizard\n";
                        getline(std::cin, temp);

                        auto user2 = new Wizard(temp);
                        players.push_back(user2);
                        yeetusDeletus = true;
                    }
                        break;
                    case 3: {
                        std::cout << "Enter your name, young Rogue\n";
                        getline(std::cin, temp);

                        auto user3 = new Rogue(temp);
                        players.push_back(user3);
                        yeetusDeletus = true;
                    }
                        break;
                    case 4: {
                        std::cout << "Enter your name, young Gunslinger\n";
                        getline(std::cin, temp);

                        auto user4 = new Gunslinger(temp);
                        players.push_back(user4);
                        yeetusDeletus = true;
                    }
                        break;
                }
            }
        }
    }

        play(players);
}



