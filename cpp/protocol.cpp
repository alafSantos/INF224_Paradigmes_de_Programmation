#include "protocol.h"

std::string protocolDealer(std::string request, Manager &media)
{

    if (request == "lGrp")
    {
        return media.listGroup();
    }
    else if (request == "lMlt")
    {
        return media.listMultimedia();
    }
    else if(request.substr(0, 4) == "addV"){
        const std::string codeEndLine = "ç;1";
        std::string fileName = "me.mp4";
        std::string path = "media/";
        int length = 10;
        media.addVideo(fileName, path, length);
        return "adding " + fileName + codeEndLine;
    }
    else
    {
        std::string command = request.substr(0, 4);
        int stringSize = request.length() - 5; // 5 à cause d'un space

        if (stringSize > 0)
        {
            std::string name = request.substr(5, stringSize);

            if (command == "play")
            {
                return media.playMultimedia(name);
            }
            else if (command == "find")
            {
                return media.find(name);
            }
            else if (command == "sFnd")
            {
                return media.sFind(name);
            }
            else if (command == "remv")
            {
                return media.remove(name);
            }
            else
            {
                return "command not found";
            }
        }
        else
            return "Please, provide a name!";
    }
}
