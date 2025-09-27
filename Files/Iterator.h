#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>

class Iterator{
    public:
        virtual ~Iterator(){
            //nothing
        }
        virtual void first()=0;
        virtual void next()=0;
        virtual bool isDone()=0;
        virtual std::string currentItem()=0;
};

#endif