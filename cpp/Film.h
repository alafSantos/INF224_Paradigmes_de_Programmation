/*
 * Développé par Alaf do Nascimento Santos
 * INF224 Paradigmes de Programmation
 * 2023
 */

#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video
{
private:
    int allChaptersSize = 0;
    int *allChapters = nullptr;

public:
    Film() : Video(){};                                // constructeur simple, sans paramètres
    Film(const int *allChapters, int allChaptersSize); // Constructeur qui fait l'Initialisation du tableau allChapters
    ~Film();                                           // Destructeur qui libère la mémoire du pointé *allChapters

    const int getAllChaptersSize() const;                   // tous les éléments
    const int *getChapters() const;                         // obtenir le pointeur allChapters
    const int getChapterSize(int i) const;                  // un seul chapitre (position)
    void setChapters(const int *chapters, int chapterSize); // définir le tableau de chapitres
    void showVariables(std::ostream &dst) const;            // Afficher les attributs via le terminal
    std::string showVariables() const;                      // envoyer les attributs au client TCP sous forme de chaîne de caractères

    // On peut redéfinir les opérateurs de copie pour faire de la copie profonde
    Film(const Film &from);
    Film &operator=(const Film &from);
};

#endif