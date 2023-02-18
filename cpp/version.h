/**
 * @file version
 * @author Alaf do Nascimento Santos
 * @brief INF224 Paradigmes de Programmation
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Dans ce fichier header il est défini des identifiants pour chaque version du projet afin qu'il soit possible 
 * de comprendre le déroulement et l'avancement du projet. Il est important de ne garder qu'une seule version
 * active pour une bonne compilation et un bon comportement (sauf pour les versions qui sont dépendantes, mais
 * le traitement est déjà fait ici via ifdef et ifndef). 
 * 
 */

#ifndef VERSION_H
#define VERSION_H

// #define VERSION_ETAPES_1_5 // pour le code de traitement uniforme (en utilisant le polymorphisme)
// #define VERSION_ETAPES_6_8 // pour le code de création des groupes
// #define VERSION_ETAPES_9 // Pour l'usage de smart pointers
// #define VERSION_ETAPES_10_11 // Manager and Client / serveur
#define JAVA_SWING // La version finale du logiciel est donnée par l'identifiant JAVA_SWING.

#ifdef VERSION_ETAPES_9
    #define VERSION_ETAPES_6_8
#endif

#ifdef VERSION_ETAPES_10_11
    #ifndef VERSION_ETAPES_9
        #define VERSION_ETAPES_9
    #endif
#endif

#ifdef JAVA_SWING
    #ifndef VERSION_ETAPES_9
        #define VERSION_ETAPES_9
    #endif
#endif

#endif