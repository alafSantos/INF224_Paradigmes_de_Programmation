#ifndef GROUP_H
#define GROUP_H

#include <memory>
#include <list>
#include "Multimedia.h"
#include "version.h"

#ifdef VERSION_ETAPES_9
typedef std::shared_ptr<Multimedia> MultimediaPtr;
class Group : public std::list<MultimediaPtr>
#endif

#ifndef VERSION_ETAPES_9
class Group : public std::list<Multimedia*>
#endif
{
private:
    std::string name;

public:
    Group(std::string name); // constructeur
    std::string getName() const; // accesseur
    void showGroup(std::ostream &dst) const; // méthode d'affichage
};

#endif