#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class List : public Node<T> {
private:
    unsigned int length;
public:
    List();
    List(unsigned int _length);
    List(const List<T> &other);
    ~List();

    List& operator=(const List<T>& other);
    inline bool operator==(const List<T>& other) const;

    int setLength(unsigned int newLength);
    unsigned int getLength() const;

    int setElement(unsigned int pos, T val);
    T getElement(unsigned int pos) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);

    template <typename U>
    friend std::istream& operator>>(std::istream& is, List<U>& list);
};

#include "List.cpp"

#endif
