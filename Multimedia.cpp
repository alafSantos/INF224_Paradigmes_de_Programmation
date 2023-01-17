#include "Multimedia.h"

Multimedia::Multimedia(){
    this->path = "path undefined";
}

Multimedia::Multimedia(std::string name, std::string path){
    this->path = path;
    this->fileName = name;
}

std::string Multimedia::getPath() const{
    return this->path;
}

std::string Multimedia::getFileName() const{
    return this->fileName;
}

void Multimedia::setPath(std::string path){
    this->path = path;
}

void Multimedia::setFileName(std::string name){
    this->fileName = name;
}

void Multimedia::showVariables(std::ostream &dst) const{
    dst << "Path: " << this->getPath() << std::endl;
    dst << "File Name: " << this->getFileName() << std::endl;
}
