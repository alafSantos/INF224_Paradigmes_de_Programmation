/**
 * @file Manager.cpp
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'implémentation de la classe Manager
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */
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
    if (this->multimediaTable.empty())
        return nullptr;

    auto it = this->multimediaTable.find(name);
    if (it != multimediaTable.end())
        return it->second;

    return nullptr;
}

std::string Manager::find(std::string name)
{
    std::string txt = this->showMultimedia(name) + this->showGroup(name);
    return txt;
}

std::string Manager::remove(std::string name)
{
    std::string txt = this->removeMultimedia(name) + this->codeEndLine;
    txt += this->removeGroup(name) + this->codeEndLine;
    return txt;
}

std::string Manager::showMultimedia(std::string name)
{
    if (!multimediaTable.count(name))
        return "No media named: " + name + " was found." + this->codeEndLine;
    else
        return this->multimediaTable[name]->showVariables() + this->codeEndLine;
}

std::string Manager::showGroup(std::string name)
{
    if (!groupTable.count(name))
        return "No group named: " + name + " was found." + this->codeEndLine;
    else
        return this->groupTable[name]->showGroup() + this->codeEndLine;
}

std::string Manager::playMultimedia(std::string name)
{
    if (multimediaTable.count(name))
    {
        multimediaTable[name]->play();
        return ("playing " + name);
    }
    return (name + " not found.");
}

std::string Manager::removeMultimedia(std::string name)
{
    std::string txt = "";
    if (multimediaTable.count(name))
    {
        this->multimediaTable.erase(this->multimediaTable.find(name));
        txt = "Deleting media " + name + this->codeEndLine;
    }
    else
        txt = "No media named \"" + name + "\" was found.";

    return txt;
}

std::string Manager::removeGroup(std::string name)
{
    std::string txt = "";
    if (groupTable.count(name))
    {
        this->groupTable.erase(this->groupTable.find(name));
        txt = "Deleting group " + name + this->codeEndLine;
    }
    else
        txt = "No group named \"" + name + "\" was found.";
    return txt;
}

std::string Manager::listGroup()
{
    if (this->groupTable.empty())
        return "No group found.";

    std::string txt;
    for (auto const &x : this->groupTable)
        txt += x.first + this->codeEndLine;
    return txt;
}

std::string Manager::listMultimedia()
{
    if (this->multimediaTable.empty())
        return "No media found.";

    std::string txt;
    for (auto const &x : this->multimediaTable)
        txt += x.first + this->codeEndLine;
    return txt;
}