//
// Created by Seth on 5/2/19.
//

#include "Orcs.h"


Orcs::Orcs() {
    Orcs::name = "Orc";
    Orcs::weaponDmg = 5;
    Orcs::agility = 6;
    Orcs::health = 50;
    //Orcs::isOrc = true;
    Orcs::weaponType = "club";
    Orcs::weapon = "club";
}

void Orcs::setResource(double resource) {
    this->resource =0;
}
