/**
 * @file Group.h
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'en-tête de la classe Group
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Cette classe sert à contenir un groupe d'objets dérivant de la classe de base.
 * Un groupe peut contenir un ensemble d'objets similaires (e.g. un groupe pour toutes les photos et un autre pour toutes les vidéos) ou pas (e.g. un groupe pour les photos et vidéos de vacances)
 *
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

public:
    Group(std::string name);                 /**Constructeur*/
    std::string getName() const;             /**Accesseur*/
    std::string showGroup() const;           /**Méthode d'affichage pour le client TCP*/
    void showGroup(std::ostream &dst) const; /**Méthode d'affichage pour le terminal*/
};

#endif