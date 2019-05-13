//
// Created by Erik on 5/2/19.
//

#ifndef CIT66FINALPROJ_PROBLEM_H
#define CIT66FINALPROJ_PROBLEM_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Items.h"
#include "Medicine.h"
#include <fstream>
#include "player.h"

using namespace std;
class player;
class Problem {
protected:
    string prompt;
public:
    const string &getPrompt() const;
    virtual bool action(player *player1);

};


#endif //CIT66FINALPROJ_PROBLEM_H
