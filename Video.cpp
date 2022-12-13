#include "Video.h"

Video::Video(){
    this->length = 0;
}

Video::Video(std::string fileName, std::string path, unsigned int length):
Multimedia(fileName, path),
length(length){}

Video::~Video(){
    std::cout << "Bye, Video..." << std::endl;
}

void Video::setLength(unsigned int length){
    this->length = length;
}

const unsigned int Video::getLength(){
    return this->length;
}

const void Video::play(){
    std::string str = "mpv " + this->getPath() + this->getFileName() + " &";
    system(str.data());
}

const void Video::showVariables(std::ostream &dst){
    Multimedia::showVariables(dst);
    dst << "Video Length: " << this->getLength() << std::endl;
}