//
// Created by sethsan on 5/2/19.
//

#ifndef CIT66FINALPROJ_FIGHT_H
#define CIT66FINALPROJ_FIGHT_H


#include "Problem.h"

class fight : public Problem{
public:
    fight();
    bool action(player* player1);
    bool action(player* player1, bool isboss);
};
bool fightMenu(player* player1, player* player2, bool isBoss);
int desicsionMaker(player* player1, player* player2, bool isBoss);
bool useItem(player* player1);

#endif //CIT66FINALPROJ_FIGHT_H
