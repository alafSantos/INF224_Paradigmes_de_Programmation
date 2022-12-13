#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia
{
private:
    float latitude;
    float longitude;

public:
    Photo(std::string fileName, std::string path, float latitude, float longitude);
    ~Photo();
    void setLatitude(float latitude);
    void setLongitude(float longitude);
    const float getLatitude();
    const float getLongitude();
    void play();

    const void showVariables(std::ostream &s);
};

#endif