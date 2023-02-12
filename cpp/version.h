#ifndef VERSION_H
#define VERSION_H

// #define VERSION_ETAPES_1_5 // pour le code de traitement uniforme (en utilisant le polymorphisme)
// #define VERSION_ETAPES_6_8 // pour le code de création des groupes
// #define VERSION_ETAPES_9 // Pour l'usage de smart pointers
// #define VERSION_ETAPES_10_11 // Manager and Client / serveur
#define JAVA_SWING

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