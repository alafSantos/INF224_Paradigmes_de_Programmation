/*
 * Développé par Alaf do Nascimento Santos
 * INF224 Paradigmes de Programmation
 * 2023
 */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "Manager.h"
#include <string>
#include <sstream>

/*
    LIST OF COMMANDS
    play  - plays a multimedia file. Example: 'play me.jpg'
    find  - seeks a multimedia file or group. Example: 'find me.jpg'
    sFnd* - uses a string argument in order to search a multimedia file or group of same name
    remv - remove a group or multimedia
    lGrp - list all groups
    lMlt - list all multimedias
    addV - add a new video
    addP - add a new video
*/

std::string protocolDealer(std::string request, Manager &media);

#endif