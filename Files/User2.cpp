/**
 * @file User2.cpp
 * @brief Implementation of the User2 class
 * @author Nyashadzashe
 * @date 2025
 */

#include <iostream>

#include "User2.h"

User2::User2(std::string name):Users(name){
    //nothing
}


//this is my get()
//users may receive data differently, i.e admin only gets important updates so I want it to be pure virtual
void User2::receive(std::string message, Users* fromUser, ChatRoom* room) {
    std::cout << name << " received in room from " << fromUser->getName() << ": " << message << std::endl;
}

//where is my set() ?? maybe no set here? or is that the command executeAll stuff??