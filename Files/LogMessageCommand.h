#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H

#include "Command.h"

class LogMessageCommand: public Command{
    public:
        void execute();
        LogMessageCommand(ChatRoom* room, std::string message, Users* fromUser);
};


#endif