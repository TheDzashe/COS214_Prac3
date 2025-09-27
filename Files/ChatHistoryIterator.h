/**
 * @file ChatHistoryIterator.h
 * @brief Concrete iterator for traversing chat history
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef CHATHISTORYITERATOR_H
#define CHATHISTORYITERATOR_H

#include "Iterator.h"
#include <vector>

class ChatRoom;

/**
 * @class ChatHistoryIterator
 * @brief Concrete iterator implementation for traversing chat message history
 * 
 * This class implements the Iterator pattern to provide a way to traverse through the chat history without exposing the underlying storage structure.
 * It maintains a copy of the chat history for iteration.
 */
class ChatHistoryIterator: public Iterator{
private:
    size_t currentPosition;                      ///< Current position in the iteration
    std::vector<std::string> chatHistoryCopy;    ///< Copy of the chat history for traversal

public:
    /**
     * @brief Construct a new ChatHistoryIterator object
     * @param history Reference to the vector containing chat history to iterate over
     */
    ChatHistoryIterator(const std::vector<std::string>& history);
    
    /**
     * @brief Reset the iterator to the first element
     */
    void first();
    
    /**
     * @brief Move the iterator to the next element
     */
    void next();
    
    /**
     * @brief Check if the iterator has reached the end
     * @return true if iteration is complete, false otherwise
     */
    bool isDone();
    
    /**
     * @brief Get the current item pointed to by the iterator
     * @return std::string The current chat message
     * @return Empty string if iteration is done
     */
    std::string currentItem();
};

#endif