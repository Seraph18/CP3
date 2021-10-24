#include "NodeHeader.h"
#include <iostream>


using namespace std;

template <typename T>    
NodeHeader<T>::NodeHeader()
{
    this->nElements = 0;
    this->firstNode = nullptr;
    this->lastNode = nullptr;
}

//Desructor
template <typename T>    
NodeHeader<T>::~NodeHeader(){
    //todo
    Node *currNode = this->firstNode;
}




template <typename T>
void NodeHeader<T>::addNewNode(T newValue){
    Node<T> newNode = new Node<T>(newValue);
    lastNode->next = newNode;
    ++nElements;
}

template <typename T>
bool NodeHeader<T>::removeFirst(){
    if(firstNode == nullptr)
        return false;

    Node<T> *newFirst = firstNode->next;
    delete &firstNode;
    firstNode = newFirst;
    return true;
}

template <typename T>
bool NodeHeader<T>::removeLast(){
    if(lastNode == nullptr){
        return false;
    }

    Node<T> *currNode = firstNode;
    for (int i = 0; i < nElements - 2; ++i){
        currNode = currNode->next;
    }
    currNode->next = nullptr;
    return true;
}


template <typename T>
bool NodeHeader<T>::isPresent(T itemToFind){
    if(!checkHeaderValid()){
        return false;
    }

    Node<T> *currNode;
    

    for (currNode = this->firstNode; currNode != nullptr; currNode = currNode->next){
        if(currNode->getData() == itemToFind){
            return true;
        }

    }

        return true;
}

template <typename T>
void NodeHeader<T>::printList(){

    Node<T> *currNode;

    for (currNode = this->firstNode; currNode != nullptr; currNode = currNode->next){
        cout << "Data: " << currNode->getData() << endl;
    }
}

template <typename T>
bool NodeHeader<T>::checkHeaderValid(){
    if(this->firstNode == nullptr){
        return false;
    }
    else if(this->nElements < 0){
        return false;
    }

    return true;
}