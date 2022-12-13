/*
    INF224 - Paradigmes de programmation, théorie et pratique
    Travaux Pratiques C++/Objet
    Élève : Alaf do Nascimento Santos
*/

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"

using namespace std;

int main(int argc, const char* argv[])
{
    // unsigned int size = 2;

    Multimedia *media = new Multimedia("fakePath/", "file.png");
    // Multimedia *tabMedia = new Multimedia[size];

    // tabMedia[0] = new Photo("fakePath/", "file.png", 2.2, 3.5);
    // tabMedia[1] = new Video("fakePath/", "file.png", 45);

    media->showVariables(std::cout);

    // for(unsigned int i = 0; i < size; i++){
    //     tabMedia[i]->play();
    // }

    // delete tabMedia;
    delete media;
    return 0;
}
