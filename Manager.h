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
    MultimediaMap multimediaTable;
    GroupMap groupTable;

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
    void showMultimedia(std::string name);

    /* Jouer */
    void playMultimedia(std::string name);

    /* Supprimer */
    void removeMultimedia(std::string name);
    void removeGroup(std::string name);
};

#endif