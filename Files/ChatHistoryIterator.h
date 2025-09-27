#ifndef CHATHISTORYITERATOR_H
#define CHATHISTORYITERATOR_H

#include "Iterator.h"

#include <vector>

class ChatRoom;

class ChatHistoryIterator: public Iterator{
    private:
        //const ChatRoom* chatRoom;
        size_t currentPosition;
        std::vector<std::string> chatHistoryCopy; //this will be a copy of the chat history
    public:
        ChatHistoryIterator(const std::vector<std::string>& history);
        void first();
        void next();
        bool isDone();
        std::string currentItem();
};
#endif