#include <string>
#include <string.h>

using namespace std;

class Activity{

public:
    string getName(){ return activityName; }

private:
    string activityName;
    string creator;
};