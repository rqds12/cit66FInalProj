//
// Created by Erik on 4/30/19.
//

#include <iostream>
#include "player.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <sstream>
#include "Problem.h"
#include "Shop.h"
#include "fight.h"
#include "Paladin.h"
#include "Wizard.h"
#include "Gunslinger.h"
#include "Rogue.h"

player::player(){
    this->createProblems(5);
}
player::~player() {
    alive = false;
}

void player::displayStatus() {
    cout << endl << endl << endl << endl << endl;
    cout << "Name: " << this->getName() << "\n"
            "Class: " << this->getType() << "\n"
            "Weapon: " <<this->getWeapon() << "\n"
            "Weapon Type: " << this->getWeaponType() << "\n"
            "Health: " << this->getHealth() << "\n"
             "Money: " << this->getMoney() << "\n"
             "Armor: " << this->getArmor() << "\n"
             << this->getResourceName() << ": " << this->getResource() << endl <<endl;

}
void player::fightDisplay(){
    cout << endl << endl;
    cout << "Name: " << this->getName() << "\tClass: " << this->getType() << "\n"
             "Health: " << this->getHealth() << "\tArmor: " << this->getArmor() << "\n" <<
             "Money: " << this->getMoney() << "\t" << this->getResourceName() << ": " << this->getResource() << endl <<endl<<endl;

}

bool player::dodge(player *target) {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 50);
    double toHitRoll = distribution(generator);
    if (toHitRoll < target->getAgility()) {
        // Attack is Dodged
        std::cout << name << " attacks " << target->getName() << " with their " << weapon << ", but "
                  << target->getName() <<
                  " artfully dodges " << "the attack causing embarrassment for " << name << ".\n\n";
        return false;
    }
    else{
        return true;
    }
}

bool player::attack(player *target) {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 100);
    if (dodge(target)) {
        double dmg = distribution(generator) + weaponDmg;
        std::cout << name << " attacks " << target->getName() << " with their " << weapon
                  << " and delivers a destructive blow causing " << dmg << " points of damage.\n\n";
        this->setMoney(this->getMoney() + 3);
        this->setResource((this->getResource()) * 1.35);
        return target->takeDamage(dmg, false);
    }
    else{
        return false;
    }
}

bool player::takeDamage(double dmg,bool ispoison) {
    //checks if the attack poisons
    int originalDmg = dmg;
    if (!ispoison) {
        if (armor > 0 && (dmg >= armor)) {
            std::cout << name << "'s armor blocks " << armor << " points of the incoming " << "damage.\n\n";

            dmg -= armor;
            if (((armor -= (originalDmg * 0.70))<=0)||armor >= 350 || armor < 0){
                armor = 0;
            }

        }else if (armor > 0 && (armor >= dmg)){
            std::cout << name << "'s armor blocks all " << (dmg) << " points of the incoming damage.\n\n";
            if (((armor - (dmg * 0.70))<=0)||armor >= 350 || armor < 0){
                armor = 0;
            }
            if((dmg * 0.70)>=armor){
                armor = 0;
            }
            else{
                armor -= dmg*0.70;
            }
            dmg = 0;
        }
        else{
            std::cout << name << " takes " << dmg << " damage. They are gravely wounded as their armor has failed them"<<endl;
        }
    }
    //poison decrementor
    if (poisoned){
        health -=dmg + (--popo);
    }
    else {
        health -= dmg;
    }
    //death msg
    if (health <= 0){
        cout << name << " breathes their last breath while cursing the bane for failing their path. "<<
     " It is truly a dark day for the empire...\n\n"<< name << " has died.\n\n";

    return true;
    }
    return false;
}

bool player::specialAbility(player *target) {
    return false;
}

const std::string &player::getName() const {
    return name;
}
void player::setName(const std::string &name) {
    player::name = name;
}
const std::string &player::getWeapon() const {
    return weapon;
}
void player::setWeapon(const std::string &weapon) {
    player::weapon = weapon;
}
double player::getHealth() const {
    return health;
}
void player::setHealth(double health) {
    player::health = health;
}
const std::string &player::getResourceName() const {
    return resourceName;
}
void player::setResourceName(const std::string &resourceName) {
    player::resourceName = resourceName;
}
double player::getResource() const {
    return resource;
}
void player::setResource(double resource) {
    player::resource = resource;
}
double player::getArmor() {
    return armor;
}
void player::setArmor(double armor) {
    player::armor = armor;
}
double player::getWeaponDmg() const {
    return weaponDmg;
}
void player::setWeaponDmg(double weaponDmg) {
    player::weaponDmg = weaponDmg;
}
int player::getAgility() const {
    return agility;
}
void player::setAgility(int agility) {
    player::agility = agility;
}
bool player::isPoisoned() const {
    return poisoned;
}
void player::setPoisoned(bool poisoned) {
    player::poisoned = poisoned;
}
const string &player::getType() const {
    return type;
}
void player::setType(const string &type) {
    player::type = type;
}

bool player::usePotion(Medicine *medicine, int a) {

    if(this->isPoisoned()&&medicine->isCurePoison()){
        poisoned = false;
    }
    player::health += medicine->getHealingPower();

    delete medicine;
    player::bag.erase(bag.begin()+a);

    return false;
}

const std::vector<std::string> &player::getStoryLine() const {
    return storyLine;
}

void player::setStoryLine(const std::vector<std::string> &storyLine) {
    player::storyLine = storyLine;
}

bool player::read() {
    return false;
}
std::string parse(std::string temp){
   int a=temp.find("=");
    temp.erase(temp.begin(), temp.begin()+a+2);
    return temp;
}
player* setRead() {
    player* things;
    auto problems = new std::vector<Problem*>;
     std::vector<Items*> bag;
    std::string temp2[5];
    std::string temp, temp1 ="";

    int a =0;
    int b =a;
    int c =a;
    std::ifstream read;
    read.open("../data.txt");
    if(read.good()){
        //class
        getline(read, temp, ';');
         temp = parse(temp);
         if(temp == "Paladin"){
             things = new Paladin(temp1);
         }else if(temp == "Wizard"){
             things = new Wizard(temp1);
         }else if(temp == "Rogue"){
             things = new Rogue(temp1);
         }else if(temp == "Gunslinger"){
             things = new Gunslinger(temp1);
         }
         things->setType(temp);
         //name
         getline(read, temp, ';');
         temp = parse(temp);
         things->setName(temp);
         //location of Story
         getline(read, temp, ';');
         temp = parse(temp);
         things->setLocationOfStory(std::stoi(temp));
         getline(read, temp, ';');
         temp = parse(temp);
         things->setLocationOfProblems(std::stoi(temp));
         //
         //problems
         getline(read, temp, ';');
         temp = parse(temp);
        std::istringstream temp3(temp);
        for (int i = 0; i <5 ; ++i) {
            getline(temp3, temp, ',');
            Problem* stuff;
            if(temp == "fight"){
                stuff = new fight;
                problems->push_back(stuff);
            }else{
                stuff = new Shop;
                problems->push_back(stuff);
            }
        }
        things->setProblems(*problems);
        //numOfItems
        getline(read, temp, ';');
        temp = parse(temp);
        a = std::stoi(temp);
        //items
        getline(read, temp, ';');
        temp = parse(temp);
        std::istringstream temp4(temp);
        for (int i = 0; i < (a) ; ++i) {
            getline(temp4, temp, ',');
            Medicine* stuff = new Medicine;
            stuff->setName(temp);
            getline(temp4, temp, ',');
            stuff->setHealingPower(std::stoi(temp));
            getline(temp4, temp, ',');
            stuff->setCurePoison(std::stoi(temp));
            bag.push_back(stuff);
        }
        things->setBag(bag);
        //health
        getline(read, temp, ';');
        temp = parse(temp);
       things->setHealth(std::stod(temp));
        //armor
        getline(read, temp, ';');
        temp = parse(temp);
        things->setArmor(std::stod(temp));
        //weaponDmg
        getline(read, temp, ';');
        temp = parse(temp);
        things->setWeaponDmg(std::stod(temp));
        //gold
        getline(read, temp, ';');
        temp = parse(temp);
        things->setMoney(std::stod(temp));
        //resource
        getline(read, temp, ';');
        temp = parse(temp);
        things->setResource(std::stod(temp));

        //agility
        getline(read, temp, ';');
        temp = parse(temp);
        things->setAgility(std::stoi(temp));



    }else{
        read.close();
    }
    read.close();
return things;
}

int player::getLocationOfStory() const {
    return LocationOfStory;
}

void player::setLocationOfStory(int locationOfStory) {
    LocationOfStory = locationOfStory;
}

int player::getLocationOfProblems() const {
    return LocationOfProblems;
}

void player::setLocationOfProblems(int locationOfProblems) {
    LocationOfProblems = locationOfProblems;
}


bool player::write(int locationOfStory, int locationOfProblems) {
    std::ofstream write;
    write.open("../data.txt");
    if(write.good()){
        write << "Class = " << type << ";\n";
        write << "Name = " << name << ";\n";
        write << "LocationOfStory = " << locationOfStory << ";\n";
        write << "LocationOfProblems = " << locationOfProblems << ";\n";
        write << "ListOfProblems = ";
        for (int i = 0; i < problems.size() ; ++i) {
            write << (problems)[i]->getPrompt() << ",";
        }
        write << ";\n";
        write << "NumberOfItems = " << numOfItems << ";\n";
        write << "ListOfItems = ";
        //have to dynamic cast
        Medicine* medicine = new Medicine;
        for (int j = 0; j < bag.size() ; ++j) {
            if (dynamic_cast<Medicine *> (bag[j])) {

                medicine = dynamic_cast<Medicine*> (bag[j]);
                write << medicine->getName() << "," << medicine->getHealingPower() << ","  << medicine->isCurePoison()<<",";

            }

        }
        delete medicine;
        write << ";\n";
        write << "Health = " << health << ";\n";
        write << "Armor = " << armor << ";\n";
        write << "WeaponDmg = " << weaponDmg << ";\n";
        write << "Gold = " << money << ";\n";
        write << "Resource = " << resource << ";\n";
        write << "Agility = " << agility << ";\n";

        write.close();

    }
    return true;
}
const string &player::getWeaponType() const {
    return weaponType;
}
void player::setWeaponType(const string &weaponType) {
    player::weaponType = weaponType;
}
double player::getMoney() const {
    return money;
}
void player::setMoney(double money) {
    player::money = money;
}


void player::shop() {
    bool yeetusDeletus = false;
    while (!yeetusDeletus) {
        int a = 0;
        cout << "=============================" << endl;
        cout << "==Welcome to Ye Olde Shoppe==" << endl;
        cout << "=============================" << endl;
        cout << "=============================" << endl;
        cout << "Welcome " << this->getName() << ", you have " << this->getMoney() << " gold to spend...\n"
             << endl;

        cout << "1) Medicinal Herbs (+25 health)............8 gold\n"
                "2) " << getWeaponType()
             << " Sharpening/Reforging by the local Armorer (+5 Damage)............14 gold\n"
                "3) Leather Breastplate (+6 Armor)............6 gold\n"
                "4) Iron Breastplate (+8 Armor)............8 gold\n"
                "5) A good kick in the pants (-2 health)............1 gold\n"
                "6) Short Sword, good for blocking and knifing political opponents in the back (+17 Damage)............30 gold\n"
                "7) Exit"
             << endl << endl;
        //todo: make poison thingamagig
        cout << "Enter your selection: " << endl;
        cin >> a;
        switch (a) {
            case 1: {
                if (this->getMoney()>=8){
                    auto medicine = new Medicine("Medicinal Herbs", 25);
                    this->bag.push_back(medicine);
                    this->setMoney(this->getMoney()-8);
                    this->setNumOfItems(numOfItems+1);
                }
                else{
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16,false);
                }
            }
            break;

            case 2: {
                if (this->getMoney()>=14) {
                    this->setWeaponDmg(this->getWeaponDmg() + 5);
                    this->setMoney(this->getMoney()-14);
                }
                else{
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16,false);
                }
            }
                break;
            case 3: {
                if (this->getMoney() >= 6) {
                    this->setArmor(this->getArmor() + 6);
                    this->setMoney(this->getMoney()-6);
                }
                else {
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16, false);
                }
            }
                break;
            case 4: {
                if (this->getMoney()>= 8){
                    this->setArmor(this->getArmor() + 8);
                    this->setMoney(this->getMoney()-8);
                }
                else{
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16,false);
                }
            }
                break;
            case 5: {
                if (this->getMoney()>=1){
                    this->setHealth(this->getHealth() - 2);
                    this->setMoney(this->getMoney()-1);
                }
                else{
                    cout << "You obviously need this gold more than I do... By the way, here is a sword and some weed" << endl;
                    this->setWeaponDmg(this->getWeaponDmg()+17);
                    this->setMoney(this->getMoney()+12);
                    Medicine *medicine = new Medicine("Herbs", 25);
                    this->bag.push_back(medicine);
                    this->setNumOfItems(numOfItems+1);

                }
            }
                break;
            case 6: {
                if (this->getMoney()>= 30){
                    this->setWeaponDmg(this->getWeaponDmg() + 17);
                    this->setMoney(this->getMoney()-30);
                }
                else{
                    cout << "Shop owner beats you with a cricket bat for being a hooligan" << endl;
                    this->takeDamage(16,false);
                }
            }
                break;
            case 7: {
                return;
            }

            default:{
                    cout << "Shop owner beats you severely with a cricket bat for being a hooligan" << endl;
                this->takeDamage(35,false);

            }
        }


    }
}

bool player::getisEnemy() const {
    return isEnemy;
}

void player::setIsEnemy(bool isEnemy) {
    player::isEnemy = isEnemy;
}

double player::getResourceReq() const {
    return resourceReq;
}

void player::setResourceReq(double resourceReq) {
    player::resourceReq = resourceReq;
}


void player::createProblems(int n) {
    std::vector<Problem*>* problemss = new std::vector<Problem*>;
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0,100);
    int switcher = 0;
    bool ifShop = false;



    for (int i = 0; i < n; ++i) {
        int rando = distribution(generator);
            if(rando >= 10){
                rando =1;
            }else{
                rando = 0;
            }
            switcher = rando;
        switch (switcher){
            case 0:{
                Shop *shop1 = new Shop;
                problemss->push_back(shop1);
                ifShop =true;


            }
                break;
            case 1:{
                fight *fight1 = new fight;
                problemss->push_back(fight1);

            }
            break;
        }
    }
    if(!ifShop){
        problemss->pop_back();
        Shop* shop2 = new Shop;
        problemss->push_back(shop2);
    }

    setProblems(*problemss);
}

vector<Problem*> player::getProblems() const {
    return problems;
}

void player::setProblems(vector<Problem*> problems) {
    player::problems = problems;
}

const vector<Items *> &player::getBag() const {
    return bag;
}

void player::setBag(const vector<Items *> &bag) {
    player::bag = bag;
}

int player::getNumOfItems() const {
    return numOfItems;
}

void player::setNumOfItems(int numOfItems) {
    player::numOfItems = numOfItems;
}

bool player::isAlive() const {
    return alive;
}

void player::setAlive(bool alive) {
    player::alive = alive;
}


