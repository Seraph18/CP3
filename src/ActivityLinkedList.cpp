#include "LinkedList.h"


ActivityLinkedList::ActivityLinkedList(){
    this->firstNode = nullptr;
    this->nElements = 0;
}


void ActivityLinkedList::addNewNode(Activity const& newData){
    //Create new node
    ActivityNode* newNode = new ActivityNode();
    newNode->data = newData;

    //Set next pointer for the new node to the first node
    newNode->next = firstNode;
    //Set the new Node to be the firstNode
    firstNode = newNode;
}


void ActivityLinkedList::print(){
    ActivityNode *currNode;
    for (currNode = this->firstNode; currNode->next != nullptr; currNode = currNode->next)
    {
        currNode->data.print();
    }
    currNode->data.print();
}