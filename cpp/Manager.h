/*
 * Développé par Alaf do Nascimento Santos
 * INF224 Paradigmes de Programmation
 * 2023
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
#include "version.h"

// création de nouveaux types
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
    const std::string codeEndLine = "ç;1"; // symbole de fin de ligne défini pour le protocole propre

public:
    Manager(){};
    ~Manager(){};

    /* Créér */
    PhotoPtr addPhoto(std::string fileName, std::string path, int latitude, int longitude);
    VideoPtr addVideo(std::string fileName, std::string path, int length);
    FilmPtr addFilm(std::string fileName, const int *allChapters, int allChaptersSize);
    GroupPtr addGroupe(std::string name);

    /* Rechercher */
    MultimediaPtr findMultimedia(std::string name);

    /* Afficher */
    #ifdef JAVA_SWING
        std::string showMultimedia(std::string name);
        std::string showGroup(std::string name);
    #elif
        void showMultimedia(std::string name);
        void showGroup(std::string name);
    #endif
    std::string find(std::string name);

    /* Jouer */
    std::string playMultimedia(std::string name);

    /* Supprimer */
    std::string removeMultimedia(std::string name);
    std::string removeGroup(std::string name);
    std::string remove(std::string name);

    /* List Files */
    std::string listGroup();
    std::string listMultimedia();
};

#endif