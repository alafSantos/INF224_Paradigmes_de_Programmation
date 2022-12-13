#include "Multimedia.h"

Multimedia::Multimedia(){
    this->path = "path undefined";
}

Multimedia::Multimedia(std::string path, std::string name){
    this->path = path;
    this->fileName = name;
}

const std::string Multimedia::getPath(){
    return this->path;
}

const std::string Multimedia::getFileName(){
    return this->fileName;
}

void Multimedia::setPath(std::string path){
    this->path = path;
}

void Multimedia::setFileName(std::string name){
    this->fileName = name;
}

const void Multimedia::showVariables(std::ostream &s){
    s << this->getPath() << " " << this->getFileName() << std::endl;
}
