#ifndef GROUP_H
#define GROUP_H

#include <memory>
#include <list>
#include "Multimedia.h"

class Group : public std::list<Multimedia*>
{
private:
    std::string name;

public:
    Group(std::string name); // constructeur
    std::string getName() const; // accesseur
    void showGroup(std::ostream &dst) const; // méthode d'affichage
};

#endif