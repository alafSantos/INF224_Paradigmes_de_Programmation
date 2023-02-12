#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video
{
private:
    int allChaptersSize = 0;
    int *allChapters = nullptr;

public:
    Film() : Video(){};
    Film(const int *allChapters, int allChaptersSize);
    ~Film();
    
    const int getAllChaptersSize() const; // all array
    const int *getChapters() const;
    const int getChapterSize(int i) const; //a single chapter (position)
    void setChapters(const int *chapters, int chapterSize);
    void showVariables(std::ostream &dst) const;
    std::string showVariables() const;

    // On peut redéfinir les opérateurs de copie pour faire de la copie profonde
    Film(const Film& from);
    Film& operator=(const Film& from);
};

#endif