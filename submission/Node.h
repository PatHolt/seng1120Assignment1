// -------------------------------------------------
// Node.h
// -------------------------------------------------
// This .h file defines what is needed for the
// Node.cpp file. This is used in conjunction with
// LinkedList.h and LinkedList.cpp to form a linked
// list
// -------------------------------------------------
// Written by Patrick Holt
// Last update: 04/09/2022
// -------------------------------------------------

#ifndef PATRICK_NODE
#define PATRICK_NODE
#include "Student.h"
#include <string>
using namespace std;

class Node
{
    //Public Members
    public:
    
        //Typedef
        typedef Student valueType;

        //Contructors
        //Pre:  Requires a student data object as a parameter
        //Post: Creates a node object and sets data as given student data object
        Node(const valueType& object);

        //Pre: None
        //Post: Constructs a node object
        Node();

        //Deconstructor
        //Pre: None
        //Post: Deconstructs a node object
        ~Node();

        //Getters
        //Pre: Requires a node object as a parameter
        //Post: Sets next as the given node
        void setNext(Node* nextNode);

        //Pre: Requires a node object as a parameter
        //Post: Sets prev as the given node
        void setPrev(Node* prevNode);

        //Pre: Requires a student data object as a parameter
        //Post: Sets data as the given node object
        void setData(valueType& dataObject);

        //Setters
        //Pre: None
        //Post: Returns the next node in the linked list
        Node* getNext() const;
        
        //Pre: None
        //Post: Returns the previous node in the linked list
        Node* getPrev() const;

        //Pre: None
        //Post: Returns the student data object
        valueType& getData();

    //Private Members   
    private:
        valueType data;
        Node* next;
        Node* prev;

};

#endif
