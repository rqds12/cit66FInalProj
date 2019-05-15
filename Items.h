//
// Created by sethsan on 5/1/19.
//

#ifndef CIT66FINALPROJ_ITEMS_H
#define CIT66FINALPROJ_ITEMS_H

#include <string>

class Items {
protected:
    std::string name;
    std::string type;

public:


    virtual const std::string &getName() const;

     virtual void setName(const std::string &name);
};


#endif //CIT66FINALPROJ_ITEMS_H
