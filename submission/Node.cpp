// -------------------------------------------------
// Node.cpp
// -------------------------------------------------
// This .cpp file implements the class defined in
// Node.h file. This is used in conjunction with
// LinkedList.h and LinkedList.cpp to form a linked
// list
// -------------------------------------------------
// Written by Patrick Holt
// Last update: 04/09/2022
// -------------------------------------------------

#include "Node.h"
#include <cstddef>

//Constructors
Node::Node(const Node::valueType& object)
{
    data = object;
    next = NULL;
    prev = NULL;
};

Node::Node()
{
    next = NULL;
    prev = NULL;
};

//Deconstructor
Node::~Node()
{
    //Not needed currently
};

//Getters
void Node::setNext(Node* nextNode)
{
    next = nextNode;
};

void Node::setPrev(Node* prevNode)
{
    prev = prevNode;
};

void Node::setData(Node::valueType& dataObject)
{
    data = dataObject;
};

//Setters
Node* Node::getNext() const
{
    return next;
};
Node* Node::getPrev() const
{
    return prev;
};
Node::valueType& Node::getData()
{

    return data;
};
