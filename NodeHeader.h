#include "Node.h"

using namespace std;

template<typename T>

class NodeHeader{

public:
    NodeHeader<T>();
    ~NodeHeader();

    void addNewNode(T newValue);


    Node<T> *getFirstNode() { return firstNode; };
    Node<T> *getLastNode() { return lastNode; }

    bool removeFirst();
    bool removeLast();
    bool removeItem(T itemToRemove);

    bool isPresent(T itemToFind);

    void printList();

    bool checkHeaderValid();

private:
    int nElements;
    Node<T> *firstNode;
    Node<T> *lastNode;
};