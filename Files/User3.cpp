#include <iostream>

#include "User3.h"




User3::User3(std::string name):Users(name){
    //nothing
}


//this is my get()
//users may receive data differently, i.e admin only gets important updates so I want it to be pure virtual
void User3::receive(std::string message, Users* fromUser, ChatRoom* room) {
    std::cout << name << " received in room from " << fromUser->getName() << ": " << message << std::endl;
}

//where is my set() ?? maybe no set here? or is that the command executeAll stuff??