#include "Activity.h"

struct Node
{
    Node *next;
    Activity data;
};


class LinkedList
{
private:
    int nElements;
    Node *firstNode;

public:
    LinkedList();
    //~LinkedList();

    void addNewNode(Activity *a);

    void print();
};
