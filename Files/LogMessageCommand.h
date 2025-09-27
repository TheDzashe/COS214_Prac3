/**
 * @file LogMessageCommand.h
 * @brief Concrete command for logging messages in the Command design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H

#include "Command.h"

/**
 * @class LogMessageCommand
 * @brief Concrete command that handles message logging operations
 * 
 * This command encapsulates the action of saving a message to the chat history.
 * It follows the Command pattern by separating the request (logging) from the
 * execution, allowing for flexible command queuing and execution.
 */
class LogMessageCommand: public Command{
public:
    /**
     * @brief Execute the log message command
     * 
     * This method calls the saveMessage function on the chat room receiver
     * to add the message to the chat history.
     */
    void execute();
    
    /**
     * @brief Constructor for LogMessageCommand
     * @param room Pointer to the chat room where the message will be logged
     * @param message The message content to be logged
     * @param fromUser Pointer to the user who sent the message
     */
    LogMessageCommand(ChatRoom* room, std::string message, Users* fromUser);
};

#endif