/*
 * pcb.h
 * CS 433
 * Program 1
 * Bryce Kinney and Daniel Dyer
 * Version 0.1 08/29/14
 */

#ifndef __CS433_ReadyQueue__PCB__
#define __CS433_ReadyQueue__PCB__

#include <iostream>
#include <iostream>
using namespace std;


class PCB
{
private:
    int ID;
    int priority;
    string state;
public:
    PCB(); //constructor
    
    int getID();
    int getPriority();
    string getState();
    
    void setID(int);
    void setPriority(int);
    void setState(string);
};


#endif /* defined(__CS433_ReadyQueue__PCB__) */
