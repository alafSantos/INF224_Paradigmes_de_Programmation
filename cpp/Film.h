/**
 * @file Film.h
 * @author Alaf do Nascimento Santos
 * @brief Fichier d'en-tête de la classe Film
 * @version 1.0.0
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief sous-classe Film dérivant de la classe Video.
 * La principale différence est que les Films comporteront des chapitres permettant d'accéder rapidement à une partie du film
 *
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
    Film() : Video(){};                                /**Constructeur simple, sans paramètres*/
    Film(const int *allChapters, int allChaptersSize); /**Constructeur qui fait l'Initialisation du tableau allChapters*/
    ~Film();                                           /**Destructeur qui libère la mémoire du pointé *allChapters*/

    const int getAllChaptersSize() const;                   /**Tous les éléments*/
    const int *getChapters() const;                         /**Obtenir le pointeur allChapters*/
    const int getChapterSize(int i) const;                  /**Un seul chapitre (position)*/
    void setChapters(const int *chapters, int chapterSize); /**Définir le tableau de chapitres*/
    void showVariables(std::ostream &dst) const override;   /**Afficher les attributs via le terminal*/
    std::string showVariables() const override;             /**Envoyer les attributs au client TCP sous forme de chaîne de caractères*/

    /**On peut redéfinir les opérateurs de copie pour faire de la copie profonde*/
    Film(const Film &from);
    Film &operator=(const Film &from);
};

#endif