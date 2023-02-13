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

typedef std::shared_ptr<Multimedia> MultimediaPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;
typedef std::shared_ptr<Group> GroupPtr;

typedef std::map<std::string, MultimediaPtr> MultimediaMap;
typedef std::map<std::string, GroupPtr> GroupMap;

class Manager
{
private:
    MultimediaMap multimediaTable;
    GroupMap groupTable;
    const std::string codeEndLine = "ç;1";

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
    std::string sFind(std::string str);

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