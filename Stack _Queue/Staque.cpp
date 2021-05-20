#include "Staque.hpp"

#include <new>// For allocation and deallocate of memory
using namespace std;

// Definition of stackque constructor
Staque::Staque()
: myTop(0), myTail(0), highestOrderNum(0)
{}

// Definition of copy constructor
Staque::Staque(const Staque & original)
: myTop(0), myTail(0), highestOrderNum(original.highestOrderNum) {
       if (!original.empty()) {
           // copy first node
           myTop = myTail = new Staque::Node(original.myTop->data,
                                             original.myTop->orderNum);
           
           // Set pointers to run through the stacks’ linked lists
           Staque::NodePointer currPtr = myTop,
                       orgPtr = original.myTop->next;
           
           
        while (orgPtr != 0)
        {
            currPtr->next = myTail = new Staque::Node(orgPtr->data,
                                                     original.myTop->orderNum);
            currPtr = currPtr->next;
           orgPtr = orgPtr->next;
        }
    }
}

// Definition of destructor
Staque::~Staque() {
    // Set pointers to run through the stackque
    Staque::NodePointer crntPtr = myTop,  // node to be deallocated
                       nextToPoint;          // its successor
    while (crntPtr != 0) {
        nextToPoint = crntPtr->next;
       delete crntPtr;
        crntPtr = nextToPoint;
    }
 }


// Definition of assignment operator=
const Staque & Staque::operator= (const Staque & rightHandSide) {
    if (this != &rightHandSide) {        // check that it's not the same object
       this->~Staque();                  // destroy current linked list
        if (rightHandSide.empty()) {      // empty Staque
            myTop = 0;
            myTail = 0;
            highestOrderNum = 0;
        }
        else
        {                                // copy rightHandSide's list
          // Copy first node
           myTop = myTail = new Staque::Node(rightHandSide.myTop->data,
                                             rightHandSide.myTop->orderNum);
           
           // Set pointers to run through the stacks’ linked lists
           Staque::NodePointer lastToPtr = myTop,
            rhsHndToPtr =  rightHandSide.myTop->next;
           
            while (rhsHndToPtr != 0)
            {
                lastToPtr->next = myTail = new Staque::Node(rhsHndToPtr->data,
                                                         rightHandSide.myTop->orderNum);
                lastToPtr = lastToPtr->next;
                rhsHndToPtr = rhsHndToPtr->next;
            }
        }
    }
    return *this;
}

// Definition of detele()
// follows the LIFO rule:
// delete given number of numbers
void Staque::detele(StaqueElement total) {
    if(total > 0){
        for(int i = 0; i < total; i++) {
           if (myTop != 0){
               // create pointers for assistance
               Staque::NodePointer ptr = myTop;
               Staque::NodePointer prvptr = ptr;
               // point to the node that has the highest order number
               while(ptr->orderNum != highestOrderNum){
                   prvptr = ptr;
                   ptr = ptr->next;
               }
               // if mytop is pointing to the node
               if(ptr == myTop){
                   myTop = myTop->next;
                   delete ptr;
               }
               // if is is the last node, but not the first
               else if(ptr->next == 0){
                   prvptr->next = 0;
                   myTail = prvptr;
                   delete ptr;
               }
               else
                   cerr << "*** can't remove a value ***\n";

               highestOrderNum--;
            }
            else
                cerr << "*** Staque is empty -- can't remove a value ***\n";
        }
    }
    else
        cerr << "*** Cannot perform deletion ***\n";
}



void Staque::detele(StaqueElement odd, StaqueElement even) {
    if (myTop != 0) {
        // create pointers for assistance
        Staque::NodePointer ptr;
        // delete even numbers from top
        for(int i = 0; i < even; i++) {
            ptr = myTop;
            if(ptr->data % 2 == 0) {
                myTop = myTop->next;
                delete ptr;
            }
            else{
                cerr << "*** Cannot remove any more even numbers ***\n";
                break;
            }
        }
        
        Staque::NodePointer prvptr;
        //delete odd numbers from bottom
        for(int i = 0; i < odd; i++) {
            ptr = myTop;
            prvptr = ptr;
            //get to the last node
            while(ptr->next != 0) {
                prvptr = ptr;
                ptr = ptr->next;
            }
            if(ptr->data % 2 == 1) {
                prvptr->next = 0;
                myTail = prvptr;
                delete ptr;
            }
            else {
                cerr << "*** Cannot remove any more odd numbers ***\n";
                break;
            }
        }
        //update highest order number of the object
        ptr = myTop;
        StaqueElement lclOrderNum = ptr->orderNum;
        while(ptr->next != 0) {
            ptr = ptr->next;
            if(ptr->orderNum > lclOrderNum) {
                lclOrderNum = ptr->orderNum;
            }
        }
        highestOrderNum = lclOrderNum;
    }
}

//Definition of deteleNegative()
//follows the LIFO rule:
void Staque::deteleNegative(StaqueElement total) {
    if(total > 0) {
        //initialize a local order number of the object
        StaqueElement lclOrderNum = highestOrderNum;
        StaqueElement count = 0;
        Staque::NodePointer ptr;
        Staque::NodePointer prvptr;
        while(count < total) {
           if (myTop != 0) {
               // create pointers for assistance
               ptr = myTop;
               prvptr = ptr;
               // point to the node that has the highest order number
               while(ptr->next != 0) {
                   if(ptr->orderNum == lclOrderNum)
                       break;
                   prvptr = ptr;
                   ptr = ptr->next;
               }
               // check if it is negative
               if(ptr->data < 0) {
                   // if mytop is pointing to the node
                   if(ptr == myTop){
                       myTop = myTop->next;
                       delete ptr;
                   }
                   // if is is the last node, but not the first
                   else if(ptr->next == 0) {
                       prvptr->next = 0;
                       myTail = prvptr;
                       delete ptr;
                   }
                   // if the node is not at the begging,
                   // nor at the end of the list
                   else{
                       prvptr->next = ptr->next;
                       delete ptr;
                   }
                   // change the object's highest order number accordingly
                   if(highestOrderNum - 1 == lclOrderNum - 1)
                       highestOrderNum--;
                   count++;
               }
               lclOrderNum--;
           }
           else
           {
               cerr << "*** Staque is empty -- can't remove a value ***\n";
               break;
           }
            if(lclOrderNum <= 0)
            {
                cerr << "*** All negative numbers are removed ***\n";
                break;
            }
        }
    }
    else
        cerr << "*** Cannot perform deletion ***\n";
}
        

// Definition of insert()
// even is pushed in front of the Staque,
// odd is pushed at the end of the Staque
void Staque::insert(StaqueElement numToStore){
    if(empty())// if myTop is empty
    {
        highestOrderNum++;
        myTop = myTail = new Staque::Node(numToStore, highestOrderNum);
    }
    else if(numToStore % 2 == 0)// if the passed value is even
    {
        // make top point to the new node
        // and this node to the one top was pointing before
        highestOrderNum++;
        myTop = new Staque::Node(numToStore, highestOrderNum, myTop);
    }
    else// if the passed value is odd
    {
        // make the node tail is pointing point to the new node
        // and make tail point to this new node too
        highestOrderNum++;
        myTail->next = new Staque::Node(numToStore, highestOrderNum);
        myTail = myTail->next;
    }
}

// Definition of display()
void Staque::display(ostream & out) const {
    Staque::NodePointer ptr;
   for (ptr = myTop; ptr != 0; ptr = ptr->next)
      out << ptr->data << endl;
}

// Definition of empty()
bool Staque::empty() const {
   return (myTop == 0);
}
