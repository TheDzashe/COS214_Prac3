/**
 * @file ChatHistoryIterator.cpp
 * @brief Implementation of the ChatHistoryIterator class
 * @author Nyashadzashe
 * @date 2025
 */

#include "ChatHistoryIterator.h"
#include "ChatRoom.h"

#include <iostream>

ChatHistoryIterator::ChatHistoryIterator(const std::vector<std::string>& history){
    
    currentPosition = 0;
    chatHistoryCopy = history; //! I don't think I need to handle deletion since vector STL should handle deletion
    std::cout << "ChatHistoryIterator created with " << chatHistoryCopy.size() << " messages" << std::endl;
}

void ChatHistoryIterator::first(){
    currentPosition=0;
}

void ChatHistoryIterator::next(){
    if(!isDone()){
        currentPosition++;
    }
}

bool ChatHistoryIterator::isDone(){
    if (currentPosition >= chatHistoryCopy.size()) {
        return true;
    } 
    else 
    {
        return false;
    }
}

std::string ChatHistoryIterator::currentItem(){
    if (isDone()) {
        return "";
    } 
    else {
        if (currentPosition < chatHistoryCopy.size()) {
            return chatHistoryCopy[currentPosition];
        } 
        else 
        {
            return "";
        }
    }
}