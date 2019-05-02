#include <iostream>
#include <string>
#include "Paladin.h"
#include "player.h"
#include "Wizard.h"
#include "Rogue.h"


int main() {
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

            Paladin user(temp);
        }
            break;
        case 2: {
            std::cout << "Enter your name young Wizard\n";
            getline(std::cin, temp);

            Wizard user(temp);
        }
            break;
        case 3:{
            std::cout << "Enter your name young Rogue\n";
            getline(std::cin, temp);

            Rogue user(temp);

        }
            break;
        default:
            std::cout << "You're a hooligan\n";
            break;


    }


    return 0;
}