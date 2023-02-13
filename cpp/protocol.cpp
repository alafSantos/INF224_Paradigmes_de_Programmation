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
    else if (request.substr(0, 4) == "addV")
    {
        int stringSize = request.length() - 5; // 5 à cause d'un space
        std::string str = request.substr(5, stringSize);
        std::string word;
        std::stringstream iss(str);
        std::string parameters[3];

        int i = 0;
        while (iss >> word)
            parameters[i++] = word;

        const std::string codeEndLine = "ç;1";

        media.addVideo(parameters[0], parameters[1], stoi(parameters[2]));
        return "adding " + parameters[0] + codeEndLine;
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
