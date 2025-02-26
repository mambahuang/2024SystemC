#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
protected:
    T* _Node;

public:
    Node();
    Node(unsigned int _length);
    ~Node();
    T* reCreate(unsigned int _length);
};

#include "Node.cpp"

#endif
