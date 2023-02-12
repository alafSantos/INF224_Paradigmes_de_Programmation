#include "Photo.h"

Photo::Photo(){
    this->latitude = 0;
    this->longitude = 0;
}

Photo::Photo(std::string fileName, std::string path, float latitude, float longitude):
Multimedia(fileName, path),
latitude(latitude),
longitude(longitude){}

Photo::~Photo(){
    std::cout << "Bye, Photo..." << std::endl;
}

void Photo::setLatitude(float latitude){
    this->latitude = latitude;
}

void Photo::setLongitude(float longitude){
   this->longitude = longitude; 
}

float Photo::getLatitude() const{
    return this->latitude;
}

float Photo::getLongitude() const{
    return this->longitude;
}

const void Photo::play(){
    std::string str = "imagej " + this->getPath() + this->getFileName() + " &";
    system(str.data());
}

void Photo::showVariables(std::ostream &dst) const{
    Multimedia::showVariables(dst);
    dst << "Photo latitude: " << this->getLatitude() << std::endl;
    dst << "Photo longitude: " << this->getLongitude() << std::endl;
}

std::string Photo::showVariables() const{
    std::string txt = Multimedia::showVariables() + this->codeEndLine;
    txt += "Photo latitude: " + std::to_string(this->getLatitude()) + this->codeEndLine;
    txt += "Photo longitude: " + std::to_string(this->getLongitude()) + this->codeEndLine;
    return txt;
}