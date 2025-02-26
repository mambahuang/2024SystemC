#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <iostream>

class List : public Node {
private:
    unsigned int length;

public:
    List();
    List(unsigned int _length);
    List(const List &other);
    ~List();

    List& operator=(const List& other);

    int setLength(unsigned int newLength);
    unsigned int getLength() const;

    int setElement(unsigned int pos, long val);
    long getElement(unsigned int pos) const;

    List operator+(const List &other) const;
    List& operator+=(const List &other);
    
    List operator++();         // Prefix increment
    List operator++(int);      // Postfix increment
    List operator--();         // Prefix decrement
    List operator--(int);      // Postfix decrement

    friend std::ostream& operator<<(std::ostream &out, const List &list);
    friend std::istream& operator>>(std::istream &in, List &list);
};

#endif // LIST_H
