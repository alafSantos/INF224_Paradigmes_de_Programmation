/**
 * @file Photo.cpp
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'implémentation de la classe Photo
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Photo.h"

Photo::Photo()
{
    this->latitude = 0;
    this->longitude = 0;
}

Photo::Photo(std::string fileName, std::string path, float latitude, float longitude) : Multimedia(fileName, path),
                                                                                        latitude(latitude),
                                                                                        longitude(longitude) {}

Photo::~Photo()
{
    std::cout << "Bye, Photo..." << std::endl;
}

void Photo::setLatitude(float latitude)
{
    this->latitude = latitude;
}

void Photo::setLongitude(float longitude)
{
    this->longitude = longitude;
}

float Photo::getLatitude() const
{
    return this->latitude;
}

float Photo::getLongitude() const
{
    return this->longitude;
}

const void Photo::play()
{
    std::string str = "imagej " + this->getPath() + this->getFileName() + " &";
    system(str.data());
}

void Photo::showVariables(std::ostream &dst) const
{
    Multimedia::showVariables(dst);
    dst << "Photo latitude: " << this->getLatitude() << std::endl;
    dst << "Photo longitude: " << this->getLongitude() << std::endl;
}

std::string Photo::showVariables() const
{
    const std::string codeEndLine = "ç;1"; // symbole de fin de ligne défini pour le protocole propre
    std::string txt = Multimedia::showVariables() + codeEndLine;
    txt += "Photo latitude: " + std::to_string(this->getLatitude()) + codeEndLine;
    txt += "Photo longitude: " + std::to_string(this->getLongitude()) + codeEndLine;
    return txt;
}