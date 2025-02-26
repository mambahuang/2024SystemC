#include "List.h"
#include <iostream>
using namespace std;

template <typename T>
List<T>::List() : Node<T>(), length(0) {}

template <typename T>
List<T>::List(unsigned int _length) : Node<T>(_length), length(_length) {}

template <typename T>
List<T>::List(const List& other) : Node<T>() {
    if (other.length > 0) {
        this->length = other.length;
        this->_Node = new T[this->length];
        for (unsigned int i = 0; i < this->length; i++) {
            this->_Node[i] = other._Node[i];
        }
    } else {
        this->length = 0;
        this->_Node = nullptr;
    }
}

template <typename T>
List<T>::~List() {
    delete[] this->_Node;
    this->_Node = nullptr; // Prevent double free
    this->length = 0;
}

template <typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other) {
        delete[] this->_Node;

        if (other.length > 0) {
            this->length = other.length;
            this->_Node = new T[this->length];
            for (unsigned int i = 0; i < this->length; i++) {
                this->_Node[i] = other._Node[i];
            }
        } else {
            this->length = 0;
            this->_Node = nullptr;
        }
    }
    return *this;
}

template <typename T>
bool List<T>::operator==(const List& other) const {
    if (this->length != other.length) return false;
    for (unsigned int i = 0; i < this->length; i++) {
        if (this->_Node[i] != other._Node[i]) return false;
    }
    return true;
}

template <typename T>
int List<T>::setLength(unsigned int newLength) {
    if (this->length == 0) {
        this->_Node = this->reCreate(newLength);
        this->length = newLength;
        return 1;
    } else {
        cout << "Error: Length already set." << endl;
        return 0;
    }
}

template <typename T>
unsigned int List<T>::getLength() const {
    return this->length;
}

template <typename T>
int List<T>::setElement(unsigned int pos, T val) {
    if (pos < this->length) {
        this->_Node[pos] = val;
        return 1;
    } else {
        cout << "Error: Index out of bounds." << endl;
        return 0;
    }
}

template <typename T>
T List<T>::getElement(unsigned int pos) const {
    assert(pos < this->length && "Error: Index out of bounds.");
    return this->_Node[pos];
}

template <typename T>
ostream& operator<<(ostream& os, const List<T>& list) {
    os << "[ ";
    for (unsigned int i = 0; i < list.length; i++) {
        os << list._Node[i] << " ";
    }
    os << "]";
    return os;
}

template <typename T>
istream& operator>>(istream& is, List<T>& list) {
    unsigned int newLength;

    // Read the length of the list from the first line
    if (!(is >> newLength)) {
        cerr << "Error: Invalid list length in input file." << endl;
        return is;
    }

    // Set the length of the list
    if (!list.setLength(newLength)) {
        cerr << "Error: Unable to set list length." << endl;
        return is;
    }

    // Read the elements line by line
    for (unsigned int i = 0; i < newLength; i++) {
        T value;
        if (!(is >> value)) {
            cerr << "Error: Invalid input for List element at position " << i << "." << endl;
            break;
        }
        list.setElement(i, value);
    }

    return is;
}

