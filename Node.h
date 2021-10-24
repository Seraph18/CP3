using namespace std;
template<typename T>

class Node
{

public:
    Node();
    ~Node();
    Node(T newData);

    T getData() { return data; }

private:
    Node *next;
    T data;
};