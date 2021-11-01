#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(){
    this->firstNode = nullptr;
    this->nElements = 0;
}

template <typename T>
void LinkedList<T>::addNewNode(T const& newData){
    //Create new node
    Node<T> *newNode = new Node<T>();
    newNode->data = newData;

    //Set next pointer for the new node to the first node
    newNode->next = firstNode;  
    //Set the new Node to be the firstNode
    firstNode = newNode;
}

template <typename T>
bool LinkedList<T>::isPresent(T newValue){

    Node<T> *currNode = this->firstNode;

    while(currNode != nullptr){
        if(currNode->data == newValue){
            return true;
    }
    else{
        currNode = currNode->next;
    }
    }
    return false;
}

template <typename T>
void LinkedList<T>::print(){
    Node<T> *currNode;
    for (currNode = this->firstNode; currNode->next != nullptr; currNode = currNode->next)
    {
        currNode->data.print();
    }
    currNode->data.print();
}