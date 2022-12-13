#include "Video.h"

Video::Video(std::string fileName, std::string path, unsigned int length):Multimedia(fileName, path),length(length){}

Video::~Video(){
    std::cout << "Bye, Video..." << std::endl;
}

void Video::setLength(unsigned int length){
    this->length = length;
}

const unsigned int Video::getLength(){
    return this->length;
}

void Video::play(){
    std::string str = "imagej " + this->getPath() + this->getFileName() + " &";
    system(str.data());
}

const void Video::showVariables(std::ostream &s){

}