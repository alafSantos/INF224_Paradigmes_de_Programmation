/*
 * Développé par Alaf do Nascimento Santos
 * INF224 Paradigmes de Programmation
 * 2023
 */

#include "protocol.h"
#include "tcpserver.h"

const int PORT = 3331; // port pour le serveur tcp

using namespace std;

int main(int argc, const char *argv[])
{

#ifdef VERSION_ETAPES_1_5
    Video *myVideo = new Video("matrix.mp4", "media/", 45);
    Photo *myPhoto = new Photo("me.jpg", "media/", 2.2, 3.5);

    // traitements uniformes
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

    #ifndef VERSION_ETAPES_9
        delete myPhoto1;
        delete myPhoto2;
        delete myPhoto3;
    #endif
#endif

#ifdef VERSION_ETAPES_10_11
    // cree le TCPServer
    auto *server = new TCPServer([&](std::string const &request, std::string &response)
                                 {
        // la demande envoyée par le client au serveur
        std::cout << "request: " << request << std::endl;

        Manager media;
        media.addPhoto("me.jpg", "media/", 10, 10);

        // la réponse que le serveur renvoie au client
        response = protocolDealer(request, media);

        // retourner false fermerait la connexion avec le client
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

#ifdef JAVA_SWING
    // Les multimedias par default - ici vous pouvez mettre des nouvelles medias et groups si vous avez besoin
    Manager media;
    media.addPhoto("me.jpg", "media/", 10, 10);
    media.addPhoto("telecom.jpg", "media/", 1050, 630);
    media.addVideo("matrix.mp4", "media/", 10);
    media.addVideo("rain.mp4", "media/", 44);

    // cree le TCPServer
    auto *server = new TCPServer([&](std::string const &request, std::string &response)
                                 {
        // la demande envoyée par le client au serveur
        std::cout << "request: " << request << std::endl;

        // la réponse que le serveur renvoie au client
        response = protocolDealer(request, media);

        // retourner false fermerait la connexion avec le client
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
