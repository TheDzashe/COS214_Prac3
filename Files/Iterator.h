/**
 * @file Iterator.h
 * @brief Abstract iterator interface for the Iterator design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>

/**
 * @class Iterator
 * @brief Abstract Iterator in the Iterator design pattern
 * 
 * This class defines the standard interface for iterator objects that provide
 * sequential access to aggregate objects without exposing their underlying
 * representation. Concrete iterators implement these methods to traverse
 * different types of collections.
 */
class Iterator{
public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Iterator(){
        //nothing
    }
    
    /**
     * @brief Reset the iterator to the first element
     */
    virtual void first()=0;
    
    /**
     * @brief Move the iterator to the next element
     */
    virtual void next()=0;
    
    /**
     * @brief Check if the iterator has reached the end of the collection
     * @return bool True if there are no more elements, false otherwise
     */
    virtual bool isDone()=0;
    
    /**
     * @brief Get the current element pointed to by the iterator
     * @return std::string The current element in the collection
     */
    virtual std::string currentItem()=0;
};

#endif