#include <iostream>
#include "Classes/DS/clsMyQueue.h"

using namespace std;

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

int main()
{
    WelcomeMessage();

    clsMyQueue<int> MyQueue;

    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);

    cout << "\nMy Queue: ";
    MyQueue.Print();

    cout << "\nMy Queue Size: " << MyQueue.Size() << endl;
    cout << "\nMy Queue Front: " << MyQueue.front() << endl;
    cout << "\nMy Queue Back: " << MyQueue.back() << endl;

    MyQueue.pop();
    cout << "\nMy Queue After pop(): ";
    MyQueue.Print();
    
    // Extension #1
    cout << "\nItem (2): " << MyQueue.GetItem(2) << endl;

    // Extension #2
    MyQueue.Reverse();
    cout << "\nQueue After Reverse: ";
    MyQueue.Print();

    // Extension #3
    MyQueue.UpdateItem(2, 600);
    cout << "\nQueue After Updating Item(2) to 600: ";
    MyQueue.Print();

    // Extension #4
    MyQueue.InsertAfter(2, 800);
    cout << "\n\nQueue after Inserting 800 after Item(2) : ";
    MyQueue.Print();

    // Extension #5
    MyQueue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at front: ";
    MyQueue.Print();

    // Extension #6
    MyQueue.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at back: ";
    MyQueue.Print();

    // Extension #7
    MyQueue.Clear();
    cout << "\n\nQueue after Clear(): ";
    MyQueue.Print();

    cout << endl
         << endl;

    return 0;
}