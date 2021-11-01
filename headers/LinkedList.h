#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Activity.h"
#include "LinkedList.h"

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

    void addNewNode(T const &newValue);
    bool isPresent(T newValue);
    void print();
};

#endif