/*
 * Développé par Alaf do Nascimento Santos
 * INF224 Paradigmes de Programmation
 * 2023
 */

#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia
{
private:
    float latitude;
    float longitude;
    const std::string codeEndLine = "ç;1";

public:
    Photo();
    Photo(std::string fileName, std::string path, float latitude, float longitude);
    ~Photo();
    void setLatitude(float latitude);
    void setLongitude(float longitude);
    float getLatitude() const;
    float getLongitude() const;
    const void play() override;
    void showVariables(std::ostream &dst) const override;
    std::string showVariables() const override;
};

#endif