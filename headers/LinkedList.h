#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    Node<T> *next;
    T data;
};

template <typename T>
class LinkedList
{
private:
    int nElements;
    Node<T> *firstNode;

public:
    LinkedList();
    //~LinkedList();

    Node<T> *getFirstNode() { return firstNode; }
    int getNElements() { return nElements; }

    void addNewNode(T const &newValue);
    bool isPresent(T const &newValue);
    T *getitem(T *itemToLookFor);
    T *getitem(T const &itemToLookFor);
    void print();
};

#endif