//
// Created by sethsan on 5/2/19.
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
using namespace std;

class Problem {
private:
    string prompt;
public:
    const string &getPrompt() const;
};


#endif //CIT66FINALPROJ_PROBLEM_H
