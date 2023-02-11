/*
    INF224 - Paradigmes de programmation, théorie et pratique
    Travaux Pratiques C++/Objet
    Élève : Alaf do Nascimento Santos
*/

#include "protocol.h"
#include "version.h"
#include "tcpserver.h"

const int PORT = 3331;

using namespace std;

string protocolDealer(string request, Manager &media);

int main(int argc, const char *argv[])
{

#ifdef VERSION_ETAPES_1_5
    Video *myVideo = new Video("me.mp4", "media/", 45);
    Photo *myPhoto = new Photo("me.jpg", "media/", 2.2, 3.5);

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
    shared_ptr<Photo> myPhoto1(new Photo("me1.jpg", "media1/", 2, 2.5));
    shared_ptr<Photo> myPhoto2(new Photo("me2.jpg", "media2/", 3, 3.5));
    shared_ptr<Photo> myPhoto3(new Photo("me3.jpg", "media3/", 4, 4.5));
    shared_ptr<Photo> photos[3] = {myPhoto1, myPhoto2, myPhoto3};
#endif

#ifndef VERSION_ETAPES_9
    Photo *myPhoto1 = new Photo("me1.jpg", "media1/", 2, 2.5);
    Photo *myPhoto2 = new Photo("me2.jpg", "media2/", 3, 3.5);
    Photo *myPhoto3 = new Photo("me3.jpg", "media3/", 4, 4.5);
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

#ifdef VERSION_ETAPES_10_11
    // cree le TCPServer
    auto *server = new TCPServer([&](std::string const &request, std::string &response)
                                 {
        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;

        Manager media;
        media.addPhoto("me.jpg", "media/", 10, 10);

        // the response that the server sends back to the client
        response = protocolDealer(request, media);

        // return false would close the connecytion with the client
        return true; });

    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }
#endif

    return 0;
}
