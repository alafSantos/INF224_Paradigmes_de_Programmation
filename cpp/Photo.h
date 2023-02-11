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
    void setLatitude(float latitude);
    void setLongitude(float longitude);
    float getLatitude() const;
    float getLongitude() const;
    const void play();
    void showVariables(std::ostream &dst) const;
};

#endif