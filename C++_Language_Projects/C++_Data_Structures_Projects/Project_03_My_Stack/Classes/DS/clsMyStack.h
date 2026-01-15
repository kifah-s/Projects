#pragma once

#include <iostream>
#include "clsMyQueue.h"

using namespace std;

template <typename T>
// template <class T>

class clsMyStack : public clsMyQueue<T>
{
public:
    void push(T item)
    {
        clsMyQueue<T>::_MyList.InsertAtBeginning(item);
    }

    T Top()
    {
        return clsMyQueue<T>::front();
    }

    T Bottom()
    {
        return clsMyQueue<T>::back();
    }
};