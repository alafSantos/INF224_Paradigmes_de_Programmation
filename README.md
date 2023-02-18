# INF224 - Paradigmes de Programmation
## Alaf do Nascimento Santos


### **C++ (Backend)**

### 1e Etape: Démarrage
Dans cette première étape, il a été créer un répertoire pour les fichiers de travail. Dans ce dossier ont été placés les fichiers Makefile et main.cpp fournis dans la spécification du projet. Le principal role du Makefile s'agit de la compilation et l'exécution du programme. Du coup, le programme peut être exécuté juste en tapant la commande **make run**.

### 2e Etape: Classe de base
Por la deuxième étape, il a été ecrire la déclaration (fichier source Multimedia.h) et l'implémentation (fichier source Multimedia.cpp) de la classe de base de l'arbre d'héritage des classes d'objets multimédia. Cette classe de base contient ce qui est commun à tous les objets multimédia.

En bref, on a déclaré et implémenté deux constructeurs (un sans argument, un avec arguments), le destructeur, ainsi que les accesseurs ("getters") et modifieurs ("setters") pour pouvoir lire ou modifier les variables d'instance. En plus d'une méthode d'affichage permettant d'afficher la valeur des variables de l'objet.

### 3e Etape: Programme de test
La troisième étape est dediée à l'écriture d'un programme de test. Pour le faire, on a créé quelques instances de la classe de base (en utilisant new) dans main() et on a vérifié que la fonction d'affichage affiche correctement la valeur des attributs dans le Terminal.

### 4e Etape: Photos et videos
Ensuite, dans la quatrième partie on a implementé deux sous-classes de la classe de base, l'une correspondant à des objets photo, l'autre à objets vidéo. 

Les principales fichiers pour cette étape sont :
- Video.h
- Video.cpp
- Photo.h
- Photo.cpp

Mais aussi on a modifié le Makefile pour qu'on puisse compiler le programme.

Il est demandé :

* Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?
    - Parce qu'on a maintenant une méthode abstraite (**play**) dans cette classe, donc elle s'agit d'une classe abstraite.


### 5e Etape: Traitement uniforme (en utilisant le polymorphisme)

Le but de la cinquième étapa est de pouvoir traiter de manière uniforme une liste comprenant à la fois des photos et des vidéos sans avoir à se préoccuper de leur type. On a fait ça dans le fichier main.cpp et le morceau de code dédié à cette partie peut être trouvé dans la directive de pré-compilation **#ifdef VERSION_ETAPES_1_5**.

* Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
    - Ici le polymorphisme nous a permis de traiter des classes différentes de manière uniforme même sans connaître leur implémentation à la base.

* Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?
    - Pour démontrer le polymorphisme, j'ai créé un tableau à 2 positions contenant une vidéo et une photo. Les fichiers utilisés dans l'exemple se trouvent dans le dossier media.

* Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
    - En bref, le tableau contient des pointeurs vers les objets. J'ai utilisé ça parce qu'il n'est pas possible de mélanger le polymorphisme et les arrays.

### 6e étape. Films et tableaux

Ensuite, la sixième étape est dediée à la definition d'une sous-classe Film dérivant de la classe Video. La principale différence est que les Films comportent des chapitres permettant d'accéder rapidement à une partie du film. Pour ce faire on a utilisé un tableau d'entiers contenant la durée de chaque chapitre.

Les principales fichiers pour cette étape sont :
- Film.h
- Film.cpp

### 7e étape. Destruction et copie des objets

Pour l'étape 7, on a modifié quelques classes précédentes afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets. La raison pour cet étape s'explique par le fait que, contrairement à Java, C++ ne gère pas la mémoire dynamique automatiquement : comme il n'y a pas de **ramasse miettes**, ce qui est créé avec new occupe de la mémoire jusqu'à la terminaison du programme, sauf si on le detruit avec delete.

Il est demandé :

* Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ? 
    - Il a été necessaire de changer la classe Film pour qu'on puisse bien utiliser la memoire alloué pour le tableau d'entiers contenant la durée de chaque chapitre. Pour cela, en utilisant **new**, pour allouer la memoire, dans la fonction **setChapters**, le tableau donné en argument a été initialisé dans le tableau dynamique **allChapters**. Pour désallouer, il existe un **delete []** dans le destructeur de la classe et aussi au début de la fonction **setChapters**, parce que sans delete l'objet existe jusqu’à la fin du programme.

* La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?
    - Il s'agit d'un problème qui se pose quand on fait une copie superficielle (shallow). Alors, les pointeurs pointent sur le même adresse et de plus l'objet peux être détruit plusieurs fois. Une bonne solution pour ce type de problème est la redéfinition des opérateurs de copie pour faire de la copie profonde (deep). Telle solution a été implémentée au sein de la classe Film. Il serait également possible de les interdire.

### 8e étape. Créer des groupes

On a créé une nouvelle classe servant à contenir un groupe d'objets dérivant de la classe de base. Un groupe peut contenir un ensemble d'objets similaires (e.g. un groupe pour toutes les photos et un autre pour toutes les vidéos) ou pas (e.g. un groupe pour les photos et vidéos de vacances).

La classe groupe hérite d'une liste d'objets de la classe parente. On a défini les méthodes suivantes: un constructeur, un accesseur qui renvoie le nom du groupe et une méthode d'affichage qui affiche les attributs de tous les objets de la liste.

Les principales fichiers pour cette étape sont :
- Group.h
- Group.cpp

Il est demandé :

* Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes. On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.

On est obligé de faire la liste avec de pointeurs d'objets car on ne veut détruit que les pointeurs lors de l'appel du destructeur. Il est nécessaire de conserver les pointés, ou les objets, parce qu'ils peuvent appartenir à des différents groupes. Dans le cas du Java, il existe la ramasse-miettes, ainsi les objets ne sont détruits qu'au cas où il n'y aurait plus de références à eux.

### 9e étape. Gestion automatique de la mémoire

Dans la classe Group on a fait la définition **typedef std::shared_ptr<Multimedia> MultimediaPtr** et maintenant l'Objet Group hérite d'une liste d'objets **MultimediaPtr**. Pour qu'on puisse avoir le bon comportement dans le fichier main.cpp, on a changé les instanciations des objets Photo pour qu'ils soient smart pointers.
Et pour compiler le programme avec les modifications qu'on a fait ici, il faut déclarer le **#define VERSION_ETAPES_9** dans le fichier Group.h, si non il s'agira de le même programme de la question précédente (8e étape).

### 10e étape. Gestion cohérente des données

### 11e étape. Client / serveur

### 12e étape. Sérialisation / désérialisation

### 13e étape. Traitement des erreurs



### Java Swing (Frontend)
## L'utilisation du logiciel 

Dans le coin supérieur gauche, il y a un menu "Liste" qui donne des options pour afficher les groupes et les fichiers multimédias disponibles dans le programme, ceux-ci peuvent être modifiés via les méthodes "supprimer" et "ajouter" disponibles dans l'interface. Les groupes et multimédias disponibles peuvent être utilisés via les fonctions "Play" et "Show", la première joue le fichier et la seconde affiche les données du fichier ou du groupe. Pour cela, dans la partie supérieure de la fenêtre, il y a un champ de texte dans lequel vous devez entrer le nom du fichier ou du groupe pour lequel vous souhaitez effectuer une action, puis cliquer sur le bouton d'action souhaité ("Play" ou "Show"). Ainda nessa toolBar superior, existe uma opção para remover uma mídia ou grupo, o processo aqui é o mesmo, basta por o nome do alvo no campo de texto e então clicar sobre o botão "Remove". Le dernier bouton de cette barre d'outils est le bouton "Quitter", qui ferme l'application.

Au centre de la fenêtre, nous avons le champ de texte de sortie, où les informations qui doivent être vues par l'utilisateur sont affichées. Ainsi qu'un bouton "Clear" pour effacer tous les champs de texte de la fenêtre.

Dans la partie inférieure de la fenêtre, il y a 4 champs de saisie de texte qui doivent être utilisés pour ajouter de nouveaux médias à la liste. Pour ajouter une vidéo, mettez le nom du fichier dans le premier champ, le chemin d'accès dans le second, sa durée dans le troisième et le quatrième champ ne doit pas être utilisé (sinon le logiciel considérera ce fichier comme une Photographie). Pour ajouter une photo, vous devez mettre le nom du fichier dans le premier champ de texte, le chemin d'accès au fichier dans le deuxième champ, votre latitude dans le troisième champ et la longitude dans le quatrième champ. Dans les deux cas, seulement après avoir rempli les champs de texte appropriés, l'utilisateur doit cliquer sur le bouton "Add Media".


### Installation des dépendances

* Java Development Kit: ***sudo apt-get install openjdk-8-jdk***

* Compile and run the program (always first the server side and finally the client side): ***make run***