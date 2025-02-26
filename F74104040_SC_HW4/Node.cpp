#include "Node.h"
#include <iostream>

using namespace std;

template <typename T>
Node<T>::Node(){
    _Node = NULL;
}

template <typename T>
Node<T>::Node(unsigned int _length) {
    _Node = new T[_length];
}

template <typename T>
Node<T>::~Node() {
    delete[] _Node;
    _Node = nullptr; // Prevent dangling pointer
}

template <typename T>
T* Node<T>::reCreate(unsigned int _length) {
    delete[] _Node;
    _Node = new T[_length];
    return _Node;
}


