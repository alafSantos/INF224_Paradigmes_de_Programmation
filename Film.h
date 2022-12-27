#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video
{
private:
    int arraySize;
    int *chapterSizes;

public:
    Film();
    Film(int arraySize, int *chapterSizes);
    ~Film();
    
    int getArraySize() const;
    int *getChaptersArray() const;
    int getChapterSize(int i) const;

    void setArraySize(int size);
    void setChaptersArray(int *array, int size);

    const void showVariables(std::ostream &dst);
};

#endif