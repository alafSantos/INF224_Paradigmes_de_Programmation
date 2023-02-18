/**
 * @file protocol.h
 * @author Alaf do Nascimento Santos
 * @brief INF224 Paradigmes de Programmation
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "Manager.h"
#include <string>
#include <sstream>

/**
 * @brief LISTE DE COMMANDES
 * play - joue un fichier multimédia. Exemple : "play me.jpg".
 * find - recherche un fichier ou un groupe multimédia. Exemple : "find me.jpg".
 * remv - retire un groupe ou un multimédia. Exemple : "remv me.jpg".
 * lGrp - envoye la liste de tous les groupes. Exemple : "lGrp".
 * lMlt - envoye la liste de tous les multimedias. Exemple : "lMlt".
 * addV - ajoute une nouvelle vidéo. Exemple : "addV fileName path length".
 * addP - ajoute une nouvelle photo. Exemple : "addP fileName path latitude longitude".
 */

int getWords(std::string parameters[], std::string name); /** sépare la chaîne de paramètres en sous-chaînes pour la gestion des requêtes tcp.*/ 
std::string protocolDealer(std::string request, Manager &media); /** Méthode principale qui traite les demandes des clients pour le protocole propre. */

#endif