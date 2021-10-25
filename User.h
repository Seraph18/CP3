#include <string>

using namespace std;

class User
{
private:
    string userName;
    string firstName;
    string lastName;

public:
    User();
    //~User();

    string getUserName() { return userName; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
};
