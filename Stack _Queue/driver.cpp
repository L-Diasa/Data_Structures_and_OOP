#include <iostream>

#include "Staque.hpp"


void print(Staque st)
{ st.display(cout); }


int main() {
    
    Staque s;
    cout << "Staque s created.  Empty? " << boolalpha << s.empty() << endl;
    
    
    // add numbers to the Staque
    // first input series:
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(6);
    s.insert(8);
    s.insert(9);
    cout << "Numbers added to the Staque s." <<endl;
    cout << "Stack s empty? " << s.empty() << endl;
    cout << "Contents of Staque s (via  print):\n";
    print(s); cout << endl;// copy constructor call
    // check whether print changed anything or not
    cout << "Contents of Staque s (via  display):\n";
    s.display(cout); cout << endl;
    
    
    // 3 different removal series:
    
    s.detele(1, 2);// delete 1 odd and two even numbers
    cout << "Contents of Staque s after deletion of 1 odd and two even numbers:\n";
    print(s); cout << endl;
    
    s.detele(2);// delete given number of numbers
    cout << "Contents of Staque s after deletion of 2 numbers:\n";
    print(s); cout << endl;
    
    s.deteleNegative(3);// delete given number of negative numbers
    cout << "Contents of Staque s deletion of some negative numbers:\n";
    print(s); cout << endl;
    
    // testing assignment operator call
    Staque t, u;
    t = u = s;
    cout << "Contents of Staques t and u after t = u = s:\n";
    cout << "u:\n"; print(u); cout << endl;
    cout << "t:\n"; print(t); cout << endl;
    
    // testing copy constructor call
    Staque d = s;
    cout << "Contents of Staque d:\n";
    print(d); cout << endl;
    
    Staque l;
    cout << "Staque l created.  Empty? " << boolalpha << s.empty() << endl;
    
    // add numbers to the Staque
    // second input series:
    l.insert(-4);
    l.insert(3);
    l.insert(6);
    l.insert(-9);
    l.insert(12);
    l.insert(0);
    l.insert(7);

    cout << "Numbers added to the Staque l." <<endl;
    cout << "Stack l empty? " << l.empty() << endl;
    cout << "Contents of Staque l (via  print):\n";
    print(l); cout << endl;// copy constructor call

    // 3 different removal series:

    l.detele(0, 3);// delete 0 odd and 3 even numbers
    cout << "Contents of Staque l after deletion of 0 odd and 3 even numbers:\n";
    print(l); cout << endl;

    l.deteleNegative(3);// delete given number of negative numbers(1 by default)
    cout << "Contents of Staque l deletion of some negative numbers:\n";
    print(l); cout << endl;

    l.detele();// delete given number of numbers(1 by default)
    cout << "Contents of Staque l after deletion of 1 number:\n";
    print(l); cout << endl;
    
    
    Staque k;
    cout << "Staque k created.  Empty? " << boolalpha << k.empty() << endl;
    // add numbers to the Staque
    // third input series:
    k.insert(2);
    k.insert(15);
    k.insert(-16);
    k.insert(-9);
    k.insert(2);
    k.insert(0);
    k.insert(-3);
    
    cout << "Numbers added to the Staque k." <<endl;
    cout << "Stack k empty? " << s.empty() << endl;
    cout << "Contents of Staque k (via  print):\n";
    print(k); cout << endl;// copy constructor call
    
    // 3 different removal series:
    
    k.detele(4, 0);// delete 4 odd and 0 even numbers
    cout << "Contents of Staque k after deletion of 4 odd and 0 even numbers:\n";
    print(k); cout << endl;

    k.deteleNegative();// delete given number of negative numbers(1 by default)
    cout << "Contents of Staque k deletion of some negative numbers:\n";
    print(k); cout << endl;

    k.detele(5);// delete given number of numbers(1 by default)
    cout << "Contents of Staque k after deletion of 5 number:\n";
    print(k); cout << endl;

    
    return 0;
}
