#include "Node.h"
using namespace std;

template<typename T>
Node<T>::Node()
{
    this->data = nullptr;
    this->next = nullptr;
}

template<typename T>
Node<T>::~Node(){
    free(this->next);
}

template <typename T>
Node<T>::Node(T newData){
    this->data = newData;
    this->next = nullptr;
}