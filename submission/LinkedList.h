// -------------------------------------------------
// LinkedList.h
// -------------------------------------------------
// This .h file defines what is needed for the
// LinkedListDemo.cpp file. This is used in conjunction
// Node.h and Node.cpp to form a linked list
// -------------------------------------------------
// Written by Patrick Holt
// Last update: 04/09/2022
// -------------------------------------------------

#ifndef PATRICK_LINKEDLIST
#define PATRICK_LINKEDLIST
#include "Student.h"
#include "Node.h"
#include <string>
using namespace std;

class LinkedList
{
    //Public member functions
    public:
        //Constructors
        //Pre: None
        //Post: Constructs a linked list object
        LinkedList();

        //Deconstructor
        //Pre: None
        //Post: Deconstructs a linked list object
        ~LinkedList();

        //Setter functions
        //Pre: Requires a student data object as an argument
        //Post: Adds a node to the Head and sets the old head's prev to the new head
        void addToHead (const Node::valueType& newHead); 

        //Pre: Requires a student data object as an argument
        //Post: Adds a node to the tail and sets the old tails's next to the new tail
        void addToTail (const Node::valueType& newTail);

        //Pre: Requires a student data object as an argument
        //Post: Adds a node to the current pointer and reconnects other node next/prev
        void addToCurrent (const Node::valueType& newCurrent);


        //Getter functions
        //Pre: None
        //Post: Returns student object from the head node
        Node::valueType& getFromHead();

        //Pre: None
        //Post: Returns student object from the tail node
        Node::valueType& getFromTail();

        //Pre: None
        //Post: Returns student object from the current node
        Node::valueType& getFromCurrent();

        //Pre: None
        //Post: Returns Node object from the current node for operator overloading query
        Node* getNodeFromCurrent();

        //Pre: None
        //Post: Returns the size of the linked list
        int getSize() const;

        //Pre:None
        //Post:Returns the average of all students marks    
         const double calcAverage();

        //Pre: Requires a student name string as an argument
        //Post: Counts all versions of name and returns it as an int
        const int count(const string name);
        

        //Remove functions
        //Pre: The list can't be empty
        //Post: Removes the head node from the linked list and sets the new head
        void removeFromHead();

        //Pre: The list can't be empty
        //Post: Removes the tail node from the linked list and sets the new tail
        void removeFromTail();

        //Pre: The list can't be empty and move pointer to location of node being removed
        //Post: Removes the node on the current pointer from the linked list and replaces the neighbour nodes next/prev pointers
        void removeFromCurrent();

        //Pre: None
        //Post: Clears a linked list of all nodes
        void clear();

        //Pre: Requires a student name string as an argument
        //Post: Removes the student node with the name from the linked list
        void remove(const string name);


        //Current pointer functions
        //Pre: None
        //Post: Moves pointer to the head
        void start();

        //Pre: None
        //Post: Moves pointer to the tail
        void end();

        //Pre: None
        //Post: Moves the pointer to the next node
        void forward();

        //Pre: None
        //Post: Moves the pointer to the previous node
        void back();


        //Operator overloading
        //Pre: The argument LinkedList isn't empty
        //Post: Adds the argument linked list to the other linked list
        LinkedList& operator += (LinkedList& linkedListAddition);


    //Private member variables
    private:
    Node* head;
    Node* tail;
    Node* current;
    int size; //Counter
};

 // Pre: Requires a LinkedList to be sent after <<
 // Post: Outputs linked list data
 ostream& operator << ( ostream& out, LinkedList& outLinkedList);

#endif
