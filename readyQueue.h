/*
 * readyQueue.h
 * CS 433
 * Program 1
 * Bryce Kinney and Daniel Dyer
 * Version 0.1 09/1/14
 */


#include "PCB.h"
#include <list>
#include <iostream>
using namespace std;

  typedef PCB el_t;      // el_t is an alias for the PCB data type

  //const int MAX_SIZE = 40;  // this is the max number of elements

class queue  {

  private:
  // Data members are:
    list<el_t> el;  /* a list called el.
                           Elements will be found between front and rear but */
    
    int  count;         // how many elements do we have right now?

  public:               // prototypes to be used by the client
 
    class Underflow{};  //handles underflow exceptions

   // constructor 
   queue(); 

   //destructor 
   ~queue();

   // PURPOSE: returns the current size to make it 
   // accessible to the client caller
   int size();

   // PURPOSE: display everything in the queue from front to rear
   //  enclosed in []
   // if empty, displays [ empty ]
   void displayQueue();
    
   // PURPOSE: inserts a PCB object into the linked list based on it's priority level
   void insertProc(el_t);

   // PURPOSE: removes the PCB object at the front of the list, since that is always the highest priority job
   el_t removeHighestProc();





};           

