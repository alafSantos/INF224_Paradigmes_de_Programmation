#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

class Multimedia
{
private:
    std::string path; // le chemin complet
    std::string fileName; // le nom du fichier

public:
    /* Constructeur sans argument */
    Multimedia();

    /* Constructeur avec des arguments */
    Multimedia(std::string path, std::string name);

    /* Destructeur */
    virtual ~Multimedia() { std::cout << "I'm about to die, see ya!" << std::endl; }

    /* Accesseur */
    const std::string getPath();
    const std::string getFileName();

    /* Modifieur */
    void setPath(std::string path);
    void setFileName(std::string name);

    /* Méthode d'affichage */
    const void showVariables(std::ostream &dst);

    /* Méthode virtuel qui permette de jouer l'objet multimédia.
    L'implementation n'est-elle disponible que dans les sous-classes */
    virtual const void play() = 0;
};

#endif