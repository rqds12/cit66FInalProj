//
// Created by sethsan on 5/1/19.
//

#ifndef CIT66FINALPROJ_MEDICINE_H
#define CIT66FINALPROJ_MEDICINE_H

#include <string>
#include "Items.h"

class Medicine : protected Items {
protected:
    bool curePoison;
    double healingPower;
public:
    Medicine(std::string name, double healingPower);

    bool isCurePoison() const;

    void setCurePoison(bool curePoison);

    double getHealingPower() const;

    void setHealingPower(double healingPower);


};


#endif //CIT66FINALPROJ_MEDICINE_H
