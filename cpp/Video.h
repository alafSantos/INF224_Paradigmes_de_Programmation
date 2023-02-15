/*
 * Développé par Alaf do Nascimento Santos
 * INF224 Paradigmes de Programmation
 * 2023
 */

#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia
{
private:
    unsigned int length; // Durée

public:
    Video(std::string fileName, std::string path, unsigned int length);
    Video();
    virtual ~Video(); // Destructeur virtual à cause de la classe fille Film.h

    void setLength(unsigned int length); // Modifieur de length
    unsigned int getLength() const;      // Accesseur de length

    const void play() override;                                   // Joue la vidéo
    virtual void showVariables(std::ostream &dst) const override; // Affiche la valeur des variables de l'objet via terminal
    virtual std::string showVariables() const override;           // Affiche la valeur des variables de l'objet via TCP (retourne une string)
};

#endif