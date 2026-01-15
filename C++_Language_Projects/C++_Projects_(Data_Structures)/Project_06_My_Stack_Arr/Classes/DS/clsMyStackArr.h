#pragma once

#include <iostream>

#include "clsMyQueueArr.h"

using namespace std;

template <typename T>
// template <class T>

class clsMyStackArr : public clsMyQueueArr<T>
{
public:
    void push(T item)
    {
        clsMyQueueArr<T>::_MyList.InsertAtBeginning(item);
    }

    T Top()
    {
        return clsMyQueueArr<T>::front();
    }

    T Bottom()
    {
        return clsMyQueueArr<T>::back();
    }
};