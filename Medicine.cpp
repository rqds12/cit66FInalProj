//
// Created by sethsan on 5/1/19.
//

#include "Medicine.h"


Medicine::Medicine(std::string name, double healingPower) {
    Items::name = name;
    Medicine::healingPower = healingPower;
    curePoison=false;

}

bool Medicine::isCurePoison() const {
    return curePoison;
}

void Medicine::setCurePoison(bool curePoison) {
    Medicine::curePoison = curePoison;
}

double Medicine::getHealingPower() const {
    return healingPower;
}

void Medicine::setHealingPower(double healingPower) {
    Medicine::healingPower = healingPower;
}

