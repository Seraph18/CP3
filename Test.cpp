#include "NodeHeader.h"

using namespace std;


int main(int argc, char *argv[]){

    NodeHeader<int> linkedList;

    linkedList.addNewNode(1);
    linkedList.addNewNode(2);
    linkedList.addNewNode(3);
    linkedList.addNewNode(4);
    linkedList.addNewNode(5);

    linkedList.printList();

    return 0;
}