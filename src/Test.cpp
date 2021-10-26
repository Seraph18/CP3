#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList list1;
    Activity *a = new Activity("Basketball", "Josh Gordon", "Town Hall", true);

    list1.addNewNode(a);
    
    list1.print();

    return 0;
}
