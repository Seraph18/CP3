#include "LinkedList.h"


VenueLinkedList::VenueLinkedList(){
    this->firstNode = nullptr;
    this->nElements = 0;
}


void VenueLinkedList::addNewNode(Venue const& newData){
    //Create new node
    VenueNode* newNode = new VenueNode();
    newNode->data = newData;

    //Set next pointer for the new node to the first node
    newNode->next = firstNode;
    //Set the new Node to be the firstNode
    firstNode = newNode;
}


void VenueLinkedList::print(){
    VenueNode *currNode;
    for (currNode = this->firstNode; currNode->next != nullptr; currNode = currNode->next)
    {
        currNode->data.print();
    }
    currNode->data.print();
}