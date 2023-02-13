/*
 * Développé par Alaf do Nascimento Santos
 * INF224 Paradigmes de Programmation
 * 2023
 */

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
              class Group : public std::list<Multimedia *>
#endif
{
private:
    std::string name;
    const std::string codeEndLine = "ç;1";

public:
    Group(std::string name);                 // constructeur
    std::string getName() const;             // accesseur
    std::string showGroup() const;           // méthode d'affichage
    void showGroup(std::ostream &dst) const; // méthode d'affichage
};

#endif