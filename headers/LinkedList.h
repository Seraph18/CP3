#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Activity.h"

struct Node
{
    Node *next;
    int data;
};

struct ActivityNode
{
    ActivityNode *next;
    Activity data;
};
struct VenueNode
{
    VenueNode *next;
    Venue data;
};


class LinkedList
{
private:
    int nElements;
    Node *firstNode;

public:
    LinkedList();
    //~LinkedList();

    void addNewNode(Activity const &newValue);

    void print();
};


class ActivityLinkedList
{
private:
    int nElements;
    ActivityNode *firstNode;

public:
    ActivityLinkedList();
    //~LinkedList();

    void addNewNode(Activity const &newValue);

    void print();
};

class VenueLinkedList
{
private:
    int nElements;
    VenueNode *firstNode;

public:
    VenueLinkedList();
    //~LinkedList();

    void addNewNode(Venue const &newValue);

    void print();
};
#endif