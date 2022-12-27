# INF224 - Paradigmes de Programmation

## 1e Etape: Démarrage
Dans cette première étape, il a été créer un répertoire pour les fichiers de travail. Dans ce dossier ont été placés les fichiers Makefile et main.cpp fournis dans la spécification du projet. Le principal role du Makefile s'agit de la compilation et l'exécution du programme. Du coup, le programme peut être exécuté juste en tapant la commande **make run**.

## 2e Etape: Classe de base
Por la deuxième étape, il a été ecrire la déclaration (fichier source Multimedia.h) et l'implémentation (fichier source Multimedia.cpp) de la classe de base de l'arbre d'héritage des classes d'objets multimédia. Cette classe de base contient ce qui est commun à tous les objets multimédia.

En bref, on a déclaré et implémenté deux constructeurs (un sans argument, un avec arguments), le destructeur, ainsi que les accesseurs ("getters") et modifieurs ("setters") pour pouvoir lire ou modifier les variables d'instance. En plus d'une méthode d'affichage permettant d'afficher la valeur des variables de l'objet.

## 3e Etape: Programme de test
La troisième étape est dediée à l'écriture d'un programme de test. Pour le faire, on a créé quelques instances de la classe de base (en utilisant new) dans main() et on a vérifié que la fonction d'affichage affiche correctement la valeur des attributs dans le Terminal.

## 4e Etape: Photos et videos
Ensuite, dans la quatrième partie on a implementé deux sous-classes de la classe de base, l'une correspondant à des objets photo, l'autre à objets vidéo. 

Les principales fichiers pour cette étape sont :
- Video.h
- Video.cpp
- Photo.h
- Photo.cpp

Mais aussi on a modifié le Makefile pour qu'on puisse compiler le programme.

## 5e Etape: Traitement uniforme (en utilisant le polymorphisme)

Le but de la cinquième étapa est de pouvoir traiter de manière uniforme une liste comprenant à la fois des photos et des vidéos sans avoir à se préoccuper de leur type. On a fait ça dans le fichier main.cpp et le morceau de code dédié à cette partie peut être trouvé dans la directive de pré-compilation **#ifdef VERSION_ETAPES_1_5**.

* Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
    - Ici le polymorphisme nous a permis de traiter des classes différentes de manière uniforme même sans connaître leur implémentation à la base.

* Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?
    - Pour démontrer le polymorphisme, j'ai créé un tableau à 2 positions contenant une vidéo et une photo. Les fichiers utilisés dans l'exemple se trouvent dans le dossier media.

* Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
    - En bref, le tableau contient des pointeurs vers les objets. J'ai utilisé ça parce qu'il n'est pas possible de mélanger le polymorphisme et les arrays.

## 6e étape. Films et tableaux

## 7e étape. Destruction et copie des objets

## 8e étape. Créer des groupes

## 9e étape. Gestion automatique de la mémoire

## 10e étape. Gestion cohérente des données

## 11e étape. Client / serveur

## 12e étape. Sérialisation / désérialisation

## 13e étape. Traitement des erreurs
