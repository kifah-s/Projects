#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <typename T>
// template <class T>

class clsMyQueue
{
protected:
    clsDblLinkedList<T> _MyList;

public:
    void Print()
    {
        _MyList.PrintList();
    }

    void push(T item)
    {
        _MyList.InsertAtEnd(item);
    }

    void pop()
    {
        _MyList.DeleteFirstNode();
    }

    int Size()
    {
        return _MyList.Size();
    }

    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }

    T front()
    {
        return _MyList.GetItem(0);
    }

    T back()
    {
        return _MyList.GetItem(Size() - 1);
    }

    T GetItem(int index)
    {
        return _MyList.GetItem(index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    void UpdateItem(int index, T newValue)
    {
        _MyList.UpdateItem(index, newValue);
    }

    void InsertAfter(int index, T value)
    {
        _MyList.InsertAfter(index, value);
    }

    void InsertAtFront(T value)
    {
        _MyList.InsertAtBeginning(value);
    }
    
    void InsertAtBack(T value)
    {
        _MyList.InsertAtEnd(value);
    }
    
    void Clear()
    {
        _MyList.Clear();
    }
};