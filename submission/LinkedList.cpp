// -------------------------------------------------
// LinkedList.cpp
// -------------------------------------------------
// This .cpp file implements the class defined in
// LinkedList.h file. This is used in conjunction with
// Node.h, Node.cpp, Student.h and Student.cpp to form 
// a linked list
// -------------------------------------------------
// Written by Patrick Holt
// Last update: 04/9/2022
// -------------------------------------------------

#include "LinkedList.h"
#include <cstddef>//For nullptr & NULL
#include <iostream>//For output
using namespace std;

//Constructors
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
    size = 0;
};

//Deconstructor
LinkedList::~LinkedList()
{
    clear();
};

//Setter functions
void LinkedList::addToHead(const Node::valueType& newHead)
{
    Node* newNode = new Node(newHead);
    if(size > 0) //ensures size is more than 0
    {
        head->setPrev(newNode);
        newNode->setNext(head);
        head = head->getPrev();
        current = head;
    }
    else //Otherwise, make this the first node
    {
        head = newNode;
        tail = newNode;
        current = newNode;
    }
    size++;
};
        
void LinkedList::addToTail (const Node::valueType& newTail)
{
    Node* newNode = new Node(newTail);
    if(size > 0) //ensures size is more than 0
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = tail->getNext();
        current = head;
    }
    else //Otherwise, make this the first node
    {
        tail = newNode;
        head = newNode;
        current = newNode;
    }
    size++;
};

void LinkedList::addToCurrent (const Node::valueType& newCurrent)
{
    Node* newNode = new Node(newCurrent);
    if(size > 0) //ensures size is more than 0
    {
        newNode->setNext(current);
        newNode->setPrev(current->getPrev());
        current->setPrev(newNode);
        newNode->getPrev()->setNext(newNode);
        current = head;
    }
    else //Otherwise, make this the first node
    {
        head = newNode;
        tail = newNode;
        current = newNode;
    }
    size++;
};

//Getter functions
Node::valueType& LinkedList::getFromHead()
{
    Node::valueType& headData = head->getData();
    return headData;
};

Node::valueType& LinkedList::getFromTail()
{
    
    Node::valueType& tailData = tail->getData();
    return tailData;
};

Node::valueType& LinkedList::getFromCurrent()
{
    Node::valueType& currentData = current->getData();
    return currentData;
};

int LinkedList::getSize() const
{
    int sizeCounter = size;
    return sizeCounter;
};

const double LinkedList::calcAverage()
{
    double average = 0;
    current = head;
    while (current != NULL) //Repeats until current is NULL
    {
        average += getFromCurrent().get_score();
        forward();
    }
    average = average/size;
    return average;    
};

const int LinkedList::count(const string name)
{
    start();
    int counter = 0;
    for(;current != NULL;forward()) //moves the counter forward, then checks for null
    {
        if (name == getFromCurrent().get_name()) //checks if current is name provided
        {
            counter++;
        }
    }
    return counter;
};

//Remove functions
void LinkedList::removeFromHead()
{
    Node* tempNode;
    tempNode = head;
    head = head->getNext();
    if(head != NULL) //Checks if head is NULL
    {
        head->setPrev(NULL);
    }
    else
    {
        head = NULL;
    }
    delete tempNode;
    size--;
};

void LinkedList::removeFromTail()
{
    Node* tempNode;
    tempNode = tail;
    tail = tail->getPrev();
    if(tail != NULL) //Checks if tail is NULL
    {
        tail->setNext(NULL);
    }
    else
    {
        tail = NULL;
    }
    delete tempNode;
    size--;
};

void LinkedList::removeFromCurrent()
{
    current->getNext()->setPrev(current->getPrev());
    current->getPrev()->setNext(current->getNext());
    delete current;
    current = head;
    size--;
};

void LinkedList::clear()
{
    start();
    while(current != NULL) //Repeats if statement until current is NULL
    {
        if(current == head) //checks if current is head then removes node
        {
            removeFromHead();
            start();
        }
    }    
};

void LinkedList::remove(const string name)
    {
        start();
        while(current != NULL) //Repeats until current is NULL
        {
            if(name == getFromCurrent().get_name() && current==head) //checks if current contains name and if it is head
            {
                Node* tempNode = head;
                head = head->getNext();
                if(head != NULL) //Checks if head is NULL
                {
                    head->setPrev(NULL);
                }     
                else 
                {
                    tail = NULL;
                }
                delete tempNode;
                start();
                size--;
            }     
            else //Moves pointer to the next
            {
                current = current->getNext();
            }
                
        }
    }

//Pointer functions
void LinkedList::start()
{
    current = head;
};

void LinkedList::end()
{
    current =  tail;
};

void LinkedList::forward()
{
    current = current->getNext();
};

void LinkedList::back()
{
    current = current->getPrev();
};


//Operator overloading
LinkedList& LinkedList::operator += (LinkedList& linkedListAddition)
{
    linkedListAddition.start();
        while (linkedListAddition.getFromCurrent() != NULL); //Repeats until node is NULL
        {
            this->addToTail(linkedListAddition.current->getData()); //Adds data from node into  the add to tail function
            linkedListAddition.forward(); //Advances current forward
        } 
        return *this;
}


ostream& operator << (ostream& out, LinkedList& outLinkedList)
{
    outLinkedList.start(); //Returns current to head
    while (outLinkedList.getFromCurrent() != NULL); //Repeats until node is NULL
    {
        out << "Student Name: " << outLinkedList.getFromCurrent().get_name() << " ";
        out << "Score: " << outLinkedList.getFromCurrent().get_score() << " ";
        outLinkedList.forward();
    }
    
    return out;
};
