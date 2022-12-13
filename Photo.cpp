#include "Photo.h"

Photo::Photo(){
    this->latitude = 0;
    this->longitude = 0;
}

Photo::Photo(std::string fileName, std::string path, float latitude, float longitude):
Multimedia(fileName, path),
latitude(latitude),
longitude(longitude){}

Photo::~Photo()
{
    std::cout << "Bye, Photo..." << std::endl;
}

void Photo::setLatitude(float latitude){
    this->latitude = latitude;
}

void Photo::setLongitude(float longitude){
   this->longitude = longitude; 
}

const float Photo::getLatitude(){
    return this->latitude;
}

const float Photo::getLongitude(){
    return this->longitude;
}

const void Photo::play(){
    std::string str = "imagej " + this->getPath() + this->getFileName() + " &";
    system(str.data());
}

const void Photo::showVariables(std::ostream &dst){
    Multimedia::showVariables(dst);
    dst << "Photo latitude: " << this->getLatitude() << std::endl;
    dst << "Photo longitude: " << this->getLongitude() << std::endl;
}