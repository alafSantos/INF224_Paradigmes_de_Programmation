#ifndef GROUP_H
#define GROUP_H

#include<list>
#include "Multimedia.h"

class Group {

private:
    std::list<Multimedia*> medias;

public:
    Group();
    ~Group();

};

#endif