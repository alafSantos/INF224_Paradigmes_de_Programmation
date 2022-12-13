#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia
{
private:
    unsigned int length; // Durée

public:
    Video(std::string fileName, std::string path, unsigned int length);
    ~Video();
    void setLength(unsigned int length);
    const unsigned int getLength();
    void play();

    const void showVariables(std::ostream &s);
};

#endif