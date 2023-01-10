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
    MultimediaMap MultimediaTable;
    GroupMap GroupTable;

public:
    Manager(){};
    ~Manager(){};

    /* Créér */
    PhotoPtr createPhoto(std::string fileName, std::string path, int latitude, int longitude);
    VideoPtr createVideo(std::string fileName, std::string path, int length);
    FilmPtr createFilm(const int *allChapters, int allChaptersSize);
    GroupPtr createGroupe(std::string name);

    /* Rechercher */
    MultimediaPtr findMultimedia(std::string name);

    /* Afficher */
    std::string showMultimedia(std::string name);

    /* Jouer */
    std::string playMultimedia(std::string name);

    /* Supprimer */
    void removeMultimedia(std::string name);
    void removeGroup(std::string name);
};

#endif