#include "Film.h"

Film::Film(){
    arraySize = 0;
    chapterSizes = nullptr;
}

Film::Film(int arraySize, int *chapterSizes) :
Video(),
arraySize(arraySize), 
chapterSizes(chapterSizes){}

Film::~Film(){
    std::cout << "Bye, Film..." << std::endl;
    delete [] chapterSizes;
}

int Film::getArraySize() const{
    return this->arraySize;
}

void Film::setArraySize(int size){
    this->arraySize = size;
}

void Film::setChaptersArray(int *array, int size){
    if(chapterSizes)
        delete [] chapterSizes;

    if(array){
        this->chapterSizes = new int[size];
        for(int i = 0; i < size; i++)
            this->chapterSizes[i] = array[i];
        this->setArraySize(size);
        return;
    }

    this->arraySize = 0;
    this->chapterSizes = array;
}

int *Film::getChaptersArray() const{
    return this->chapterSizes;
}

int Film::getChapterSize(int i) const{
    return this->chapterSizes[i];
}

const void Film::showVariables(std::ostream &dst){
    Multimedia::showVariables(dst);
    dst << "Number of chapters: " << this->getArraySize() << std::endl;

    for(int i=0; i < this->getArraySize(); i++)
        dst << "Length of chapter "<< i+1 << ": " << this->getChapterSize(i) << std::endl;
}