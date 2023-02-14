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
    virtual ~Video();
    void setLength(unsigned int length);
    unsigned int getLength() const;
    const void play() override;
    virtual void showVariables(std::ostream &dst) const override;
    virtual std::string showVariables() const override;
};

#endif