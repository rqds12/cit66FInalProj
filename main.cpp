#include <iostream>
#include <string>
#include "Paladin.h"
#include "player.h"
#include "Wizard.h"
#include "Rogue.h"
#include "fight.h"

void play(std::vector <player*> players);
void startingMenu();
void play(std::vector<player*> players);
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
        return;
    }
    player *player1 = (players[0]);
    player1->displayStatus();
    //player1->shop();
    players[0]->read();
    std::vector <std::string>story = players[0]->getStoryLine();
    for (int i = 0; i < story.size(); ++i) {
        std::cout << story[i] << "\n";
    }
}
void startingMenu() {
    std::vector<player *> players;
    std::string temp;
    bool yeetusDeletus = false;
    bool yeetus2Deletus = false;

    std::cout << "Welcome to Text Adventure 3000\n" <<
              "Please Select a mode: \n"
              "1) Story Mode\n"
              "2) 2 Player" << endl;
    int a = 0;
    while (!yeetus2Deletus) {
        try {
            getline(std::cin, temp);
            a = std::stoi(temp);
            if (a != 1 && a != 2) {
                throw "hooligan";
            } else {
                yeetus2Deletus = true;
            }
        }
        catch (...) {
            cout << "Enter a choice, 1 or 2" << endl;
        }
    }
    for (int i = 0; i < a; ++i) {
        yeetusDeletus = false;
        int ii = i + 1;
        cout << "Please Select a class for player " << ii << ": \n" <<
             "1) Paladin\n" <<
             "2) Wizard\n" <<
             "3) Rogue\n";

        while (yeetus2Deletus) {
            try {
                getline(std::cin, temp);
                a = std::stoi(temp);
                if (a != 1 && a != 2 && a != 3) {
                    throw "hooligan";
                } else {
                    yeetus2Deletus = false;
                }
            }
            catch (...) {
                cout << "Enter a choice, 1 or 2 or 3" << endl;
            }
        }

        while (!yeetusDeletus) {
            switch (a) {
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
            }
        }
        play(players);
        return;
    }
}



