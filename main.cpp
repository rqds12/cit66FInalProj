#include <iostream>
#include <string>
#include "Paladin.h"
#include "player.h"
#include "Wizard.h"
#include "Rogue.h"
#include "fight.h"

void play(std::vector <player*> players);
void startingMenu();
void play();
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
        fightMenu(player1,player2);
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
void startingMenu(){
    std::vector <player*> players;
    std::string temp;
    bool yeetusDeletus = false;

    std::cout << "Welcome to Text Adventure 3000\n" <<
              "Please Select a mode: \n"
              "1) Story Mode\n"
              "2) 2 Player" << endl;
              getline(std::cin, temp);
              switch (std::stoi(temp)){
                  case 1:{
                      cout << "Please Select a class\n" <<
                           "1) Paladin\n" <<
                           "2) Wizard\n" <<
                           "3) Rogue\n";
                      getline(std::cin, temp);
                      while (!yeetusDeletus) {
                          switch (std::stoi(temp)) {
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
                              default:
                                  std::cout << "You're a hooligan\n";

                          }
                      }
                  }
                  case 2:{
                      for (int i = 0; i < 2; ++i) {
                          yeetusDeletus=false;
                          int ii=i+1;
                          cout << "Please Select a class for player " << ii << ": \n" <<
                                                                         "1) Paladin\n" <<
                                                                         "2) Wizard\n" <<
                                                                         "3) Rogue\n";
                          getline(std::cin, temp);
                          while (!yeetusDeletus) {
                              switch (std::stoi(temp)) {
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
                                  default:
                                      std::cout << "You're a hooligan\n";

                              }
                          }
                      }

                  }
              }

    play(players);
}