#include <iostream>
#include "platypus.hpp"
using namespace std;

int main() {
    //testing constructors
    Platypus hmm(1, 5, 'k', 'm');
    Platypus yo(5, 2, 'A', 'f');
    Platypus mhm;
    cout << endl;
    
    //testing getters
    cout << "Name: " << yo.getName() <<
    ". Weigth: " << yo.getWeight() << endl;
    
    cout << "Age: " << yo.getAge() <<
    ". Gender: " << yo.getGender() << endl;
    
    cout << "Alive(1 = yes, 0 = no): " << hmm.getAliveness() << endl;
    cout << "Mutant(1 = yes, 0 = no): " << hmm.getMutantness() << endl;
    
    cout << "Alive(1 = yes, 0 = no): " << mhm.getAliveness() << endl;
    cout << "Name: " << mhm.getName() << endl
    << endl;
    
    //testing setters(though mainly were checked when objects were created)
    //make hmm dead
    cout << "Alive(1 = yes, 0 = no): " << hmm.getAliveness() << endl;
    hmm.setAliveness(0);
    cout << "Alive(1 = yes, 0 = no): " << hmm.getAliveness() << endl;
    
    //make mhm alive
    cout << "Alive(1 = yes, 0 = no): " << mhm.getAliveness() << endl;
    mhm.setAliveness(1);
    cout << "Alive(1 = yes, 0 = no): " << mhm.getAliveness() << endl;

    //set hmm's name to 'N'
    cout << "Name: " << hmm.getName() << endl;
    hmm.setName('N');
    cout << "Name: " << hmm.getName() << endl
    << endl;
    
    //testing other funtions
    //print info
    yo.print(cout);
    cout << endl;
    
    //eat
    yo.eat();
    hmm.eat();
    mhm.eat();
    yo.eat();
    yo.print(cout);
    cout << endl;
    
    //age
    yo.age_me(50);
    
    hmm.setAliveness(1);
    hmm.age_me(400);
    cout << endl;
    
    //fight
    yo.fight(hmm);
    cout << endl;
    //making sure that
    //ighters are alive
    yo.setAliveness(1);
    hmm.setAge(1);
    hmm.fight(yo);
    
    //hatch
    Platypus newPlaty1 = yo.hatch();
    newPlaty1.print(cout);
    cout << endl;
    Platypus newPlaty2 = mhm.hatch();
    newPlaty2.print(cout);
    return 0;
}
