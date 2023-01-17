#include "Manager.h"

PhotoPtr Manager::addPhoto(std::string fileName, std::string path, int latitude, int longitude)
{
    PhotoPtr media = PhotoPtr(new Photo(fileName, path, latitude, longitude));
    this->multimediaTable[fileName] = media;
    return media;
}

VideoPtr Manager::addVideo(std::string fileName, std::string path, int length)
{
    VideoPtr media = VideoPtr(new Video(fileName, path, length));
    this->multimediaTable[fileName] = media;
    return media;
}

FilmPtr Manager::addFilm(std::string fileName, const int *allChapters, int allChaptersSize)
{
    FilmPtr media = FilmPtr(new Film(allChapters, allChaptersSize));
    this->multimediaTable[fileName] = media;
    return media;
}

GroupPtr Manager::addGroupe(std::string name)
{
    this->groupTable[name] = GroupPtr(new Group(name));
    return this->groupTable[name];
}

MultimediaPtr Manager::findMultimedia(std::string name)
{
    if (multimediaTable.empty())
        return nullptr;

    auto it = this->multimediaTable.find(name);
    if (it != multimediaTable.end())
        return it->second;

    return nullptr;
}

void Manager::showGroup(std::string name){
    this->groupTable[name]->showGroup(std::cout);
}

void Manager::showMultimedia(std::string name)
{
    this->multimediaTable[name]->showVariables(std::cout);
}

void Manager::playMultimedia(std::string name)
{
    if (multimediaTable.count(name))
    {
        multimediaTable[name]->play();
        return;
    }
    std::cerr << name << " not found\n";
}

void Manager::removeMultimedia(std::string name)
{
    this->multimediaTable.erase(this->multimediaTable.find(name));
}

void Manager::removeGroup(std::string name)
{
    this->groupTable.erase(this->groupTable.find(name));
}