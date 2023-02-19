/**
 * @file Manager.h
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'en-tête de la classe Manager
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Cette classe qui sert à fabriquer et manipuler tous les objets de manière cohérente.
 * Elle contient deux variables d'instance : une table de tous les objets multimédia et une table de tous les groupes
 *
 */

#ifndef MANAGER_H
#define MANAGER_H

#include <memory>
#include <map>
#include <string>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

///
/// création de nouveaux types
///
using MultimediaPtr = std::shared_ptr<Multimedia>;
using PhotoPtr = std::shared_ptr<Photo>;
using VideoPtr = std::shared_ptr<Video>;
using FilmPtr = std::shared_ptr<Film>;
using GroupPtr = std::shared_ptr<Group>;

using MultimediaMap = std::map<std::string, MultimediaPtr>;
using GroupMap = std::map<std::string, GroupPtr>;

class Manager
{
private:
    MultimediaMap multimediaTable;
    GroupMap groupTable;
    const std::string codeEndLine = "ç;1"; /**symbole de fin de ligne défini pour le protocole propre*/

public:
    Manager(){};
    ~Manager(){};

    /**Créér*/
    PhotoPtr addPhoto(std::string fileName, std::string path, int latitude, int longitude);
    VideoPtr addVideo(std::string fileName, std::string path, int length);
    FilmPtr addFilm(std::string fileName, const int *allChapters, int allChaptersSize);
    GroupPtr addGroupe(std::string name);

    /**Rechercher*/
    MultimediaPtr findMultimedia(std::string name);

    /**Afficher*/
    std::string showMultimedia(std::string name);
    std::string showGroup(std::string name);
    std::string find(std::string name);

    /**Jouer*/
    std::string playMultimedia(std::string name);

    /**Supprimer*/
    std::string removeMultimedia(std::string name);
    std::string removeGroup(std::string name);
    std::string remove(std::string name);

    /**List Files*/
    std::string listGroup();
    std::string listMultimedia();
};

#endif