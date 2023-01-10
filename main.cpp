/*
    INF224 - Paradigmes de programmation, théorie et pratique
    Travaux Pratiques C++/Objet
    Élève : Alaf do Nascimento Santos
*/

#include "Manager.h"

// #define VERSION_ETAPES_1_5 // pour le code de traitement uniforme (en utilisant le polymorphisme)
#define VERSION_ETAPES_6_8 // pour le code de création des groupes

using namespace std;

int main(int argc, const char *argv[])
{

#ifdef VERSION_ETAPES_1_5
    Video *myVideo = new Video("media/", "me.mp4", 45);
    Photo *myPhoto = new Photo("media/", "me.jpg", 2.2, 3.5);

    unsigned int size = 2;
    Multimedia *media[size];
    media[0] = myVideo;
    media[1] = myPhoto;

    cout << "---------------\n";
    for (unsigned int i = 0; i < size; i++)
    {
        media[i]->showVariables(cout);
        media[i]->play();
        cout << "---------------\n";
    }
    delete myPhoto;
    delete myVideo;
#endif

#ifdef VERSION_ETAPES_6_8
#ifdef VERSION_ETAPES_9
    shared_ptr<Photo> myPhoto1(new Photo("media1/", "me1.jpg", 2, 2.5));
    shared_ptr<Photo> myPhoto2(new Photo("media2/", "me2.jpg", 3, 3.5));
    shared_ptr<Photo> myPhoto3(new Photo("media3/", "me3.jpg", 4, 4.5));
    shared_ptr<Photo> photos[3] = {myPhoto1, myPhoto2, myPhoto3};
#endif

#ifndef VERSION_ETAPES_9
    Photo *myPhoto1 = new Photo("media1/", "me1.jpg", 2, 2.5);
    Photo *myPhoto2 = new Photo("media2/", "me2.jpg", 3, 3.5);
    Photo *myPhoto3 = new Photo("media3/", "me3.jpg", 4, 4.5);
    Photo *photos[3] = {myPhoto1, myPhoto2, myPhoto3};
#endif

    Group myPhotos1("My photos1");
    Group myPhotos2("My photos2");

    for (int i = 0; i < 3; i++)
    {
        myPhotos1.push_back(photos[i]);
        myPhotos2.push_back(photos[i]);
    }

    cout << "---------------\n";
    myPhotos1.showGroup(cout);
    cout << "---------------\n";
    myPhotos2.showGroup(cout);
    cout << "---------------\n";
#endif

    return 0;
}
