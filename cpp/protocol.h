#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "Manager.h"
#include <string>

/*
    LIST OF COMMANDS
    play  - plays a multimedia file. Example: 'play me.jpg'
    find  - seeks a multimedia file or group. Example: 'find me.jpg'
    sFnd - uses a string argument in order to search a multimedia file or group of same name
    delt - remove a group or multimedia
*/

std::string protocolDealer(std::string request, Manager &media);

#endif