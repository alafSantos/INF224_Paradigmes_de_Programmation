/**
 * @file Multimedia.cpp
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'implémentation de la classe Multimedia
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Multimedia.h"

Multimedia::Multimedia()
{
    this->path = "path undefined";
    this->fileName = "file name undefined";
}

Multimedia::Multimedia(std::string name, std::string path)
{
    this->path = path;
    this->fileName = name;
}

std::string Multimedia::getPath() const
{
    return this->path;
}

std::string Multimedia::getFileName() const
{
    return this->fileName;
}

void Multimedia::setPath(std::string path)
{
    this->path = path;
}

void Multimedia::setFileName(std::string name)
{
    this->fileName = name;
}

void Multimedia::showVariables(std::ostream &dst) const
{
    dst << "Path: " << this->getPath() << "\nFile Name: " << this->getFileName();
}

std::string Multimedia::showVariables() const
{
    const std::string codeEndLine = "ç;1"; // symbole de fin de ligne défini pour le protocole propre
    return "Path: " + this->getPath() + codeEndLine + "File Name: " + this->getFileName();
}