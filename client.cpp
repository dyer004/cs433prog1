/*
 * Client.cpp
 * CS 433
 * Program 1
 * Bryce Kinney and Daniel Dyer
 * Version 0.1 08/29/14
 */

#include "pcb.h"
#include "readyQueue.h"
#include <iostream>
using namespace std;

//Global Variables
PCB pcb_Table = new PCB[20];
queue q1;

//This functions fills the table with 20 PCB objects with random 
// priorities between 1 and 50
void 
intializeTest1(PCB *pcb_Table){
   for(int i =0; i<19;i++){
        pcb_Table[i].setID(i+1);
        pcb_Table[i].setPriority(rand() % 50 + 1);
    }  
}
//This function will add a PCB to the queue and also changes the PCB status to 
// "READY" within the pcb_Table. 
//Args: integer ID of the PCB object
void 
addToQueue(int id){
    pcb_Table[id].setState = "READY";
    q1.insertProc(pcb_Table[id]);
}
//Removes the highest priority PCB from the queue and returns it, also sets the 
// status of the PCB in the pcb_Table to "RUNNING"
int
removeFromQueue(){
    PCB temp = q1.removeHighestProc();
    int tempID = temp.getID();
    for(int i=0;i<19;i++){
        if(pcb_Table[i].getID() == tempID){
            pcb_Table[i].setState = "RUNNING";
        }
    }
    return tempID;
}

void 
runTest1(PCB *pcb_Table){
    cout<<"Test 1: pcb_table of 20 entries";
    intializeTest1(*pcb_Table);
    addToQueue(5);
    addToQueue(1);
    addToQueue(8);
    addToQueue(11);
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    addToQueue(3);
    addToQueue(7);
    addToQueue(2);
    addToQueue(12);
    addToQueue(9);
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    cout<<"Removed PCB with ID: "<<removeFromQueue()<<endl;
    q1.displayQueue();
    
}

int
main(){
    cout<<"Bryce Kinney and Daniel Dyer";
    runTest1(*pcb_Table);
    
    
    
    
}

