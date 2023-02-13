#include "protocol.h"

const std::string codeEndLine = "ç;1";

void getWords(std::string parameters[], std::string name)
{
    std::string word;
    std::stringstream iss(name);
    int i = 0;
    while (iss >> word)
        parameters[i++] = word;
}

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
    else
    {
        std::string command = request.substr(0, 4);
        int stringSize = request.length() - 5; // 5 à cause d'un space
        std::string name = request.substr(5, stringSize);

        if (request.substr(0, 3) == "add")
        {
            int width = 0;
            if (command == "addV")
                width = 3;
            else if (command == "addP")
                width = 4;

            std::string parameters[width];
            getWords(parameters, name);

            if (width == 3)
                media.addVideo(parameters[0], parameters[1], stoi(parameters[2]));
            else
                media.addPhoto(parameters[0], parameters[1], stoi(parameters[2]), stoi(parameters[3]));

            return "adding " + parameters[0] + codeEndLine;
        }
        else
        {
            if (stringSize > 0)
            {
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
}
