/*
 * readyQueue.cpp
 * CS 433
 * Program 1
 * Bryce Kinney and Daniel Dyer
 * Version 0.1 08/29/14
 */
 
#include "PCB.h"
#include "readyQueue.h"   
#include <iostream>
using namespace std;

// constructor
queue::queue()
{
    list<el_t> el;
    count = 0;
}

//destructor 
queue::~queue()
{}

// PURPOSE: returns the current size to make it
// accessible to the client caller
int queue::size()
{
    return count;
}

// PURPOSE: display everything in queue from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayQueue()
{
    cout << endl;
    cout << "Queue Contents: " << endl;
    if (el.empty()) //if queue is empty, print [ empty ]
    {
        cout << "[ empty ]" << endl;
    }
    else //if queue is not empty, print out all elements
    {
        for (list<el_t>::iterator it=el.begin(); it != el.end(); ++it)
        {
            cout << "ID: " << it->getID() << endl;
            cout << "Priority: " << it->getPriority() << endl;
            cout << endl;
        }
    }
}


void queue::insertProc(el_t e)
{
    bool inserted = false;
    
    if (el.empty()) //if list is empty
    {
        list<el_t>::iterator it = el.begin();
        el.insert(it, e); //insert PCB into beginning of list
    }
    else //if the list is not empty
    {
        int jobPriority = e.getPriority(); //get priority level of e
        list<el_t>::iterator it; //declare list iterator
        for (it=el.begin(); it != el.end() && inserted == false; it++) //for loop iterates through entire list
        {
            if (jobPriority < it->getPriority()) //if we find a job with lower priority than e
            {
                el.insert(it, e); //inserts e into list and pushes exisitng job and all others behind it back
                inserted = true;
            }
        }
        
        if (inserted == false) //if e has a lower priority than all other jobs in the list
        {
            el.push_back(e); //add e to the very end of the list
        }
        
    }
    count++;  
}

el_t queue::removeHighestProc()
{
    list<el_t>::iterator it = el.begin(); //point iterator at beginning element in list
    PCB highestProc = *it;
    el.erase(it); //erase first item in list
    return highestProc;
}


