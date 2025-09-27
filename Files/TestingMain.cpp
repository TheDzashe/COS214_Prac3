#include "ChatRoom.h"
#include "Dogorithm.h"
#include "CtrlCat.h"

#include "Users.h"
#include "User1.h"
#include "User2.h"
#include "User3.h"

#include <string>
#include <iostream>

void printLine(){
    std::cout << " " << std::endl;
}


void printSectionSpace(){
    for(int i=0; i<4; i++){
        std::cout << " " << std::endl;
    }
}

void printSectionLine(){
    std::cout << "____________________________________________________________________" << std::endl;
}

void printPatternHeader(std::string patternName){
    std::cout << "TESTING: " << patternName << " design pattern." << std::endl; 
}

int main(){
    printPatternHeader("Mediator");
    printLine();

    Users* blackPanther = new User1("Black Panther");
    Users* ironMan = new User2("Iron Man");
    Users* blackWidow = new User3("black Widow");
    Users* thor = new User1("Thor");


    ChatRoom* dogChat = new Dogorithm();
    ChatRoom* catChat = new CtrlCat();

    std::cout << "__CREATED USERS JOINING THE CHAT ROOM__" <<std::endl;
    blackPanther->joinChatRoom(catChat);
    blackWidow->joinChatRoom(catChat);
    ironMan->joinChatRoom(dogChat);
    ironMan->joinChatRoom(catChat);
    thor->joinChatRoom(dogChat);
    thor->joinChatRoom(catChat);


    printLine();
    std::cout << "__TESTING REMOVING A USER__" <<std::endl;
    dogChat->removeUser(thor);
    catChat->removeUser(thor);

    printLine();
    std::cout << "__ USER SENDING A MESSAGE__" <<std::endl;
    blackPanther->send("Hi guys", dogChat);

    ironMan->send("Hello everyone. I just joined", catChat);
    blackWidow->send("Nice to meet you Iron Man.", catChat);

    printLine();
    std::cout <<"__SEARCHING FOR A MESSAGE__" <<std::endl;
    dogChat->searchMessage("Hi");
    catChat->searchMessage("nice");

    printLine();
    catChat->saveMessage("whaaaat??", blackPanther);
    catChat->sendMessage("no wayss!!", blackWidow);

    delete blackPanther;
    delete ironMan;
    delete blackWidow;
    delete thor;

    delete dogChat;
    delete catChat;


}
