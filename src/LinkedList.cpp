#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    this->firstNode = nullptr;
    this->nElements = 0;
}

template <typename T>
void LinkedList<T>::addNewNode(T const &newData)
{
    // Create new node
    Node<T> *newNode = new Node<T>();
    newNode->data = newData;

    // Set next pointer for the new node to the first node
    newNode->next = firstNode;
    // Set the new Node to be the firstNode
    firstNode = newNode;
    ++nElements;
}

template <typename T>
bool LinkedList<T>::isPresent(T const &newValue)
{

    Node<T> *currNode = this->firstNode;

    for (int i = 0; i < this->getNElements(); ++i)
    {
        if (currNode->data == newValue)
        {
            return true;
        }
        else
        {
            currNode = currNode->next;
        }
    }
    return false;
}

template <typename T>
T* LinkedList<T>::getitem(T *itemToLookFor)
{
    Node<T> *currNode = this->firstNode;

    while (currNode != nullptr)
    {
        if (currNode->data == *itemToLookFor)
        {
            return &currNode->data;
        }
        else
        {
            currNode = currNode->next;
        }
    }
    return nullptr;
}

template <typename T>
T* LinkedList<T>::getitem(T const &itemToLookFor){
    Node<T> *currNode = this->firstNode;

    while (currNode != nullptr)
    {
        if (currNode->data == itemToLookFor)
        {
            return &currNode->data;
        }
        else
        {
            currNode = currNode->next;
        }
    }
    return nullptr;
}


template <typename T>
void LinkedList<T>::print()
{
    Node<T> *currNode;
    for (currNode = this->firstNode; currNode->next != nullptr; currNode = currNode->next)
    {
        currNode->data.print();
    }
    currNode->data.print();
}