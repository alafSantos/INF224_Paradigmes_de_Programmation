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

unsigned int Video::getLength() const{
    return this->length;
}

const void Video::play(){
    std::string str = "mpv " + this->getPath() + this->getFileName() + " &";
    system(str.data());
}

void Video::showVariables(std::ostream &dst) const{
    Multimedia::showVariables(dst);
    dst << "Video Length: " << this->getLength() << std::endl;
}

std::string Video::showVariables() const{
    const std::string codeEndLine = "ç;1";
    std::string txt = Multimedia::showVariables() + codeEndLine;
    txt += "Video Length: " + std::to_string(this->getLength()) + codeEndLine;
    return txt;
}