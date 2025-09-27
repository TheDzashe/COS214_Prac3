/**
 * @file SendMessageCommand.cpp
 * @brief Implementation of the SendMessageCommand class
 * @author Nyashadzashe
 * @date 2025
 */

#include "SendMessageCommand.h"
#include "ChatRoom.h"

void SendMessageCommand::execute(){
    room->sendMessage(message, fromUser);
}

SendMessageCommand::SendMessageCommand(ChatRoom* room, std::string message, Users* fromUser):Command(room, message, fromUser)
{
    //nothing
}
