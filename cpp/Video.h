/**
 * @file Video.h
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'en-tête de la classe Video
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Une sous-classe de la classe de base Multimedia correspondant à une vidéo.
 * Une vidéo a une durée, c'est-à-dire une valeur numérique intégrale
 *
 */

#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia
{
private:
    unsigned int length; /**Durée*/

public:
    Video(std::string fileName, std::string path, unsigned int length);
    Video();
    virtual ~Video(); /**Destructeur virtual à cause de la classe fille Film.h*/

    void setLength(unsigned int length); /**Modifieur de length*/
    unsigned int getLength() const;      /**Accesseur de length*/

    const void play() override;                                   /**Joue la vidéo*/
    virtual void showVariables(std::ostream &dst) const override; /**Affiche la valeur des variables de l'objet via terminal*/
    virtual std::string showVariables() const override;           /**Affiche la valeur des variables de l'objet via TCP (retourne une string)*/
};

#endif