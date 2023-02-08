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

std::string Manager::find(std::string name)
{
    this->showMultimedia(name);
    this->showGroup(name);
    return "showing information";
}

std::string Manager::sFind(std::string str){
    // return "showing information";
    return "implementation still missing";
}

std::string Manager::remove(std::string name)
{
    this->removeMultimedia(name);
    this->removeGroup(name);
    return "deleting data";
}

void Manager::showGroup(std::string name)
{
    if (!groupTable[name])
    {
        std::cout << "No group named: " + name + " was found.";
    }
    else
    {
        this->groupTable[name]->showGroup(std::cout);
    }
}

void Manager::showMultimedia(std::string name)
{
    if (!multimediaTable[name])
    {
        std::cout << "No media named: " + name + " was found.";
    }
    else
    {
        this->multimediaTable[name]->showVariables(std::cout);
    }
}

std::string Manager::playMultimedia(std::string name)
{
    if (multimediaTable.count(name))
    {
        multimediaTable[name]->play();
        return ("playing " + name);
    }
    return (name + " not found");
}

void Manager::removeMultimedia(std::string name)
{
    if (multimediaTable.count(name))
    {
        this->multimediaTable.erase(this->multimediaTable.find(name));
        return;
    }
    std::cout << "No media named: " + name + " was found.";
}

void Manager::removeGroup(std::string name)
{
    if (groupTable.count(name))
    {
        this->groupTable.erase(this->groupTable.find(name));
        return;
    }
    std::cout << "No group named: " + name + " was found.";
}