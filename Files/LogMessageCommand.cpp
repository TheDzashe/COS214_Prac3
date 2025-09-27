#include "LogMessageCommand.h"
#include "ChatRoom.h"

void LogMessageCommand::execute(){
    room->saveMessage(message, fromUser);
}

LogMessageCommand::LogMessageCommand(ChatRoom* room, std::string message, Users* fromUser):Command(room, message, fromUser)
{
    //nothing
}
