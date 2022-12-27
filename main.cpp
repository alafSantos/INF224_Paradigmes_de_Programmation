/*
    INF224 - Paradigmes de programmation, théorie et pratique
    Travaux Pratiques C++/Objet
    Élève : Alaf do Nascimento Santos
*/

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"

#define VERSION_ETAPES_1_5 // pour le code de traitement uniforme (en utilisant le polymorphisme)

using namespace std;

int main(int argc, const char* argv[])
{

#ifdef VERSION_ETAPES_1_5
    Video *myVideo = new Video("media/", "me.mp4", 45);
    Photo *myPhoto = new Photo("media/", "me.jpg", 2.2, 3.5);

    unsigned int size = 2;
    Multimedia *media[size];
    media[0] = myVideo;
    media[1] = myPhoto;

    std::cout << "---------------\n";
    for(unsigned int i = 0; i < size; i++){
        media[i]->showVariables(std::cout);
        media[i]->play();
        std::cout << "---------------\n";
    }
    delete myPhoto;
    delete myVideo;
#endif

    return 0;
}
