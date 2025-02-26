#include "List.h"
#include <iostream>
#include <stdexcept>

List::List() : Node(), length(0) {}

List::List(unsigned int _length) : Node(_length), length(_length) {}

List::List(const List &other) : Node(other.length), length(other.length) {
    for (unsigned int i = 0; i < length; i++) {
        _Node[i] = other._Node[i];
    }
}

List::~List() {
    length = 0;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        delete[] _Node;
        length = other.length;
        _Node = new long[length];
        for (unsigned int i = 0; i < length; i++) {
            _Node[i] = other._Node[i];
        }
    }
    return *this;
}

int List::setLength(unsigned int newLength) {
    if (length == 0) {
        reCreate(newLength);
        length = newLength;
        return 1;
    }
    std::cerr << "Error: Length already set.\n";
    return 0;
}

unsigned int List::getLength() const {
    return length;
}

int List::setElement(unsigned int pos, long val) {
    return Node::setElement(pos, val);
}

long List::getElement(unsigned int pos) const {
    return Node::getElement(pos);
}

List List::operator+(const List &other) const {
    List result(length);
    for (unsigned int i = 0; i < length; i++) {
        result._Node[i] = this->_Node[i] + other._Node[i];
    }
    return result;
}

List& List::operator+=(const List &other) {
    for (unsigned int i = 0; i < length; i++) {
        this->_Node[i] += other._Node[i];
    }
    return *this;
}

List List::operator++() {
    for (unsigned int i = 0; i < length; i++) {
        ++_Node[i];
    }
    return *this;
}

List List::operator++(int) {
    List temp(*this);
    for (unsigned int i = 0; i < length; i++) {
        _Node[i]++;
    }
    return temp;
}

List List::operator--() {
    for (unsigned int i = 0; i < length; i++) {
        --_Node[i];
    }
    return *this;
}

List List::operator--(int) {
    List temp(*this);
    for (unsigned int i = 0; i < length; i++) {
        _Node[i]--;
    }
    return temp;
}

std::ostream& operator<<(std::ostream &out, const List &list) {
    out << "[ ";
    for (unsigned int i = 0; i < list.length; i++) {
        out << list._Node[i] << " ";
    }
    out << "]";
    return out;
}

std::istream& operator>>(std::istream &in, List &list) {
    for (unsigned int i = 0; i < list.length; i++) {
        in >> list._Node[i];
    }
    return in;
}
