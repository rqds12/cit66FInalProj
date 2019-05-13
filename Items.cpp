//
// Created by sethsan on 5/1/19.
//

#include "Items.h"


const std::string &Items::getName() const {
    return name;
}

void Items::setName(const std::string &name) {
    Items::name = name;
}
