#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

class Multimedia
{
private:
    std::string path;
    std::string fileName;

public:
    /* Constructeur sans argument */
    Multimedia();

    /* Constructeur avec des arguments */
    Multimedia(std::string path, std::string name);

    /* Destructeur */
    ~Multimedia() { std::cout << "I'm about to die, see ya!" << std::endl; }

    /* Accesseur */
    const std::string getPath();
    const std::string getFileName();

    /* Modifieur */
    void setPath(std::string path);
    void setFileName(std::string name);

    /* Méthode d'affichage */
    const void showVariables(std::ostream &s);

    virtual void play();
};

#endif