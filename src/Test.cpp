#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Activity.h"

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList<Venue> list1;
    //Activity *a = new Activity("Basketball", "Josh Gordon", "Town Hall", true);

    Venue a("Stadium", "NYC", 400);
    Venue b("Field", "NYC", 400);
    list1.addNewNode(a);

    list1.print();

    return 0;
}
