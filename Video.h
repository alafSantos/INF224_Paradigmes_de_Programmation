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
    ~Video();
    void setLength(unsigned int length);
    const unsigned int getLength();
    const void play();
    const void showVariables(std::ostream &dst);
};

#endif