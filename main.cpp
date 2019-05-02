#include <iostream>
#include <string>
#include "Paladin.h"
#include "player.h"
#include "Wizard.h"
#include "Rogue.h"

void play(std::vector <player*> players);

int main() {
    std::vector <player*> players;
    std::string temp="";

    std::cout << "Welcome to Text Adventure 3000\n" <<
    "Please Select a class\n" <<
    "1) Paladin\n" <<
    "2) Wizard\n" <<
    "3) Rogue\n";
    getline(std::cin, temp);
    switch(std::stoi(temp)){
        case 1: {
            std::cout << "Enter your name young Paladin\n";
            getline(std::cin, temp);

            auto user1 = new Paladin(temp);
            players.push_back(user1);
        }
            break;
        case 2: {
            std::cout << "Enter your name young Wizard\n";
            getline(std::cin, temp);

            auto user2 = new Wizard(temp);
            players.push_back(user2);
        }
            break;
        case 3:{
            std::cout << "Enter your name young Rogue\n";
            getline(std::cin, temp);

            auto user3 = new Rogue(temp);
            players.push_back(user3);
        }
            break;
        default:
            std::cout << "You're a hooligan\n";
            return 0;


    }
        play(players);


    return 0;
}

void play(std::vector<player*> players){
    players[0]->read();
    std::vector <std::string>story = players[0]->getStoryLine();
    for (int i = 0; i < story.size(); ++i) {
        std::cout << story[i] << "\n";
    }
}