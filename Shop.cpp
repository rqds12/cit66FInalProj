//
// Created by sethsan on 5/2/19.
//

#include "Shop.h"

Shop::Shop() {
    prompt = "Shop";
}

bool Shop::action(player *player1) {
    player1->shop();
    return true;
}