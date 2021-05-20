#ifndef Staque_hpp
#define Staque_hpp

#include <iostream>
using namespace std;

typedef int StaqueElement;

class Staque
{
private:
  //Node class
    class Node
    {
    public:
        StaqueElement data;       // for storing data
        StaqueElement orderNum;   // for storing order index
        
        Node * next;              // for pointing to the next node

        // Node constructor
        Node(StaqueElement value, StaqueElement ordIndex, Node * link = 0)
        : data(value), next(link), orderNum(ordIndex)
        {}
                                                                            
    };

    typedef Node * NodePointer;

 // Data Members
NodePointer myTop,      // pointer to the top
            myTail;     // pointer to the tail
StaqueElement highestOrderNum;

    
public:
    // Function Members
    // default constructor
    Staque();
    
    // copy constructor
    Staque(const Staque & original);
    
    // destructor
    ~Staque();
    
    // assignment operator
    const Staque & operator= (const Staque & rightHandSide);
    
    // deletes given number of elements
    // following the LIFO rule
    void detele(StaqueElement total = 1);// by default it will
                                        // delete only one node
    
    // deletes given number of odd and even elements
    // odds from the bottom, evens from the begining
    void detele(StaqueElement odd, StaqueElement even);
    
    // deletes given number of negative numbers
    // following the LIFO rule
    void deteleNegative(StaqueElement total = 1);// by default it will
                                    // delete only one negative number
    
    // insertion:
    // even is pushed in front of the Staque,
    // odd is pushed at the end of the Staque
    void insert(StaqueElement numToStore);
    
    // display values stored in the staque
    void display(ostream & out) const;
    
    // check if stack is empty
    bool empty() const;
};

#endif
