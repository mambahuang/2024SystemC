#ifndef NODE_H
#define NODE_H

class Node {
protected:
    long* _Node;

public:
    // Default constructor
    Node();
    
    // Parameterized constructor
    Node(unsigned int _length);
    
    // Destructor
    ~Node();
    
    // Re-create the Node array with a new length
    long* reCreate(unsigned int _length);
    
    // Method to set an element
    bool setElement(unsigned int pos, long val);
    
    // Method to get an element
    long getElement(unsigned int pos) const;
};

#endif // NODE_H
