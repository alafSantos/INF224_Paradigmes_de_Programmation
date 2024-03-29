/**
 * @file Multimedia.h
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'en-tête de la classe Multimedia
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief  Cette classe de base contient ce qui est commun à tous les objets multimédia.
 * Ensuite elle est utilisé pour définir des sous-classes spécifiques à chaque type de donnée (par exemple une classe photo, vidéo, film, etc.)
 *
 */

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

class Multimedia
{
private:
    std::string path;     // le chemin complet
    std::string fileName; // le nom du fichier

public:
    /* Constructeur sans argument */
    Multimedia();

    /* Constructeur avec des arguments */
    Multimedia(std::string path, std::string name);

    /* Destructeur */
    virtual ~Multimedia() { std::cout << "I'm about to die, see ya!" << std::endl; }

    /* Accesseur */
    std::string getPath() const;
    std::string getFileName() const;

    /* Modifieur */
    void setPath(std::string path);
    void setFileName(std::string name);

    /* Méthode d'affichage */
    // avec virtual on a liaison dynamique / tardive -> méthode du pointé est appellé
    virtual void showVariables(std::ostream &dst) const; // méthode d'affichage pour le terminal
    virtual std::string showVariables() const;           // méthode d'affichage pour le client TCP

    /* Méthode virtuel qui permette de jouer l'objet multimédia.
    L'implementation n'est-elle disponible que dans les sous-classes */
    virtual const void play() = 0;
};

#endif