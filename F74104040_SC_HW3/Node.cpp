#include "Node.h"
#include <iostream>

Node::Node() : _Node(nullptr) {}

Node::Node(unsigned int _length) {
    _Node = new long[_length];
}

Node::~Node() {
    delete[] _Node;
}

long* Node::reCreate(unsigned int _length) {
    delete[] _Node;
    _Node = new long[_length];
    return _Node;
}

bool Node::setElement(unsigned int pos, long val) {
    if (_Node && pos >= 0) {
        _Node[pos] = val;
        return true;
    } else {
        std::cerr << "Position out of bounds.\n";
        return false;
    }
}

long Node::getElement(unsigned int pos) const {
    if (_Node && pos >= 0) {
        return _Node[pos];
    } else {
        std::cerr << "Position out of bounds.\n";
        return -99999;
    }
}
