/**
 * @file Photo.h
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'en-tête de la classe Photo
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Une sous-classe de la classe de base Multimedia correspondant à une photo.
 * Une photo peut être caractérisée par un latitude et une longitude, c'est-à-dire deux valeurs numériques réelles
 *
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

    void setLatitude(float latitude);   /**Modifieur de latitude*/
    void setLongitude(float longitude); /**Modifieur de longitude*/
    float getLatitude() const;          /**Accesseur de latitude*/
    float getLongitude() const;         /**Accesseur de longitude*/

    const void play() override;                           /**Affiche la photo*/
    void showVariables(std::ostream &dst) const override; /**Affiche la valeur des variables de l'objet via terminal*/
    std::string showVariables() const override;           /**Affiche la valeur des variables de l'objet via TCP (retourne une string)*/
};

#endif