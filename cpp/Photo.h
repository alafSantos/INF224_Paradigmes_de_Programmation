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

public:
    Photo();
    Photo(std::string fileName, std::string path, float latitude, float longitude);
    ~Photo();

    void setLatitude(float latitude);   // Modifieur de latitude
    void setLongitude(float longitude); // Modifieur de longitude
    float getLatitude() const;          // Accesseur de latitude
    float getLongitude() const;         // Accesseur de longitude

    const void play() override;                           // Affiche la photo
    void showVariables(std::ostream &dst) const override; // Affiche la valeur des variables de l'objet via terminal
    std::string showVariables() const override;           // Affiche la valeur des variables de l'objet via TCP (retourne une string)
};

#endif