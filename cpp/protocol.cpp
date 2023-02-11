#include "protocol.h"

std::string protocolDealer(std::string request, Manager &media)
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
        else if(command == "sFnd"){
            return media.sFind(name);
        }
        else if(command == "delt"){
            return media.remove(name);
        }
        else if(command == "lGrp"){
            return media.listGroup();
        }
        else if(command == "lMlt"){
            return media.listMultimedia();
        }
        else
        {
            return "command not found";
        }
    }
    else
        return "Please, provide a name!";
}
