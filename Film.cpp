#include "Film.h"

Film::Film(const int *chapters, int chapterSize) : Video()
{
    setChapters(chapters, chapterSize);
}

Film::~Film()
{
    std::cout << "Bye, Film..." << std::endl;
    delete[] this->allChapters;
}

void Film::setChapters(const int *chapters, int chapterSize)
{
    delete[] this->allChapters;

    this->allChaptersSize = 0;
    this->allChapters = nullptr;

    if (chapters && chapterSize > 0)
    {
        this->allChapters = new int[chapterSize];
        for (int i = 0; i < chapterSize; i++)
        {
            this->allChapters[i] = chapters[i];
        }
        this->allChaptersSize = chapterSize;
    }
}

const int Film::getAllChaptersSize() const
{
    return this->allChaptersSize;
}

const int *Film::getChapters() const
{
    return this->allChapters;
}

const int Film::getChapterSize(int i) const
{
    return this->allChapters[i];
}

void Film::showVariables(std::ostream &dst) const
{
    Video::showVariables(dst);
    dst << "Number of chapters: " << this->getAllChaptersSize() << std::endl;

    for (int i = 0; i < this->getAllChaptersSize(); i++)
        dst << "Length of chapter " << i + 1 << ": " << this->getChapterSize(i) << std::endl;
}

Film::Film(const Film &from) : Video(from)
{
    this->allChaptersSize = from.allChaptersSize;
    this->allChapters = from.allChapters ? new int(*from.allChapters) : nullptr;
}

Film &Film::operator=(const Film &from)
{
    Video::operator=(from);
    this->allChaptersSize = from.allChaptersSize;
    delete allChapters;
    if (this->allChaptersSize && from.allChapters)
    {
        this->setChapters(from.allChapters, from.allChaptersSize);
    }
    else
    {
        this->allChapters = nullptr;
        this->allChapters = from.allChapters ? new int(*from.allChapters) : nullptr;
    }
    return *this;
}