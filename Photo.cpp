#include "Photo.h"

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

void Photo::play(){
    std::string str = "mpv " + this->getPath() + this->getFileName() + " &";
    system(str.data());
}

const void Photo::showVariables(std::ostream &s){

}