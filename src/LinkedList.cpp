#include "LinkedList.h"

LinkedList::LinkedList(){
    this->firstNode = nullptr;
    this->nElements = 0;
}

void LinkedList::addNewNode(Activity *a){
    //Create new node
    Node *newNode = new Node();
    newNode->data = *a;

    //Set next pointer for the new node to the first node
    newNode->next = firstNode;
    //Set the new Node to be the firstNode
    firstNode = newNode;
}


void LinkedList::print(){
    Node *currNode;
    for (currNode = this->firstNode; currNode->next != nullptr; currNode = currNode->next)
    {
        currNode->data.print();
    }
    currNode->data.print();
}