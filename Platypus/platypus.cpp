/*-- platypus.hpp -----------------------------------
 The file implements the Platypus member functions
---------------------------------------------------*/
#include <iostream> //for using ostream
#include <ctype.h> // for usign isalpha function
#include <cstdlib> //for seeding
#include <ctime> //for time
#include <cmath> //for round
#include "platypus.hpp"

using namespace std;


/*----------constructors----------*/
// default constructor
Platypus::Platypus()
    : weight(0.4), age(0), name('L'),
    gender('m'), alive(0), mutant(0) {
    srand((unsigned) time(0));
}

// explicit-value constructor
Platypus::Platypus(float initWeight, short initAge,
                   char initName, char initGender) {
    // validity is checked by setters
    // so there is no need for additional if statement here.
        setAliveness(1);
        setWeight(initWeight);
        setAge(initAge);
        setName(initName);
        setGender(initGender);
        setMutantness(0);
        // seed for more different random combinations
        srand((unsigned) time(0));
}

/*----------getters----------*/
float Platypus::getWeight() const {
    return weight;
}

short Platypus::getAge() const {
    return age;
}

char Platypus::getName() const {
    return name;
}

char Platypus::getGender() const {
    return gender;
}

bool Platypus::getAliveness() const {
    return alive;
}

bool Platypus::getMutantness() const {
    return mutant;
}

/*----------setters----------*/
void Platypus::setWeight(float initWeight) {
    // if input is valid, add weight
    if(initWeight < 0)
        cerr << "The weight cannot be assigned" << endl;
    else{
        weight = initWeight;
        // if it makes makes the platypus
        //  overweighted, it will die
        if(weight > 5.4){
            alive = 0;
            cout << "The platypus died from obesity." << endl;
        }
    }
}

void Platypus::setAge(short initAge) {
    if( initAge >= 0 ){// alive == 1 &&initAge < 204 - age
        // increment age
        age = initAge;
        if(initAge > 204 - age){
            cerr << "The platypus could not live any longer" << endl;
            alive = 0;
        }
    }
    else
        cerr << "The age cannot be assigned" << endl;
}

void Platypus::setName(char initName) {
    // check if the name starts with an upper letter
    if(isalpha(initName))
        name = initName;
    else
        cerr << "The name cannot be assigned" << endl;
}

void Platypus::setGender(char initGender) {
    // check validity
    if(initGender == 'f' || initGender == 'm')
        gender = initGender;
    else
        cerr << "The gender cannot be assigned" << endl;
}

void Platypus::setAliveness(bool initAlive) {
    alive = initAlive;
}

void Platypus::setMutantness(bool initMutant) {
    mutant = initMutant;
}

/*----------other operators----------*/
// print
void Platypus::print(ostream & out) const {
    out << "The name of this platypus is " << name << "." << endl;
    out << "The platy's weight is " << weight << " pounds." << endl;
    out  << name << " is " << age << " months old and "
    << name << "'s gender is ";
    if (gender == 'f')
        out << "female." << endl;
    else
        out << "male." << endl;
    if(alive)
        out << "The platypus is alive. " <<endl;
    else
        out << "The platypus is not alive. " <<endl;
    if(mutant)
        out << "The platypus is a mutant. " <<endl;
    else
        out << "The platypus is not a mutant. " <<endl;
}

// increment age
void Platypus::age_me(short months) {
    cout << "The platypus was " << age << " months old." << endl;
    
    // check if it is alive and if the month is valid
    if(alive == 1 && months >= 1) {
        // increment age
        age += months;
        cout << "Now, the platypus is " << age << " months old." << endl;
        // a 2% chance that the object will become a mutant
        if((rand() % 50) == 0) {
            mutant = 1;
            cout << "The platypus became a mutant." << endl;
        }
        // chance of death
        if(weight >= 10) {
            alive = 0;
            cout << "The platypus could not live any longer." << endl;
        }
        else if(rand() % (int)round(100 / (10 * weight)) == 0) {
            alive = 0;
            cout << "The platypus could not live any longer." << endl;
        }
        // if adding months makes the platipus's
        // age greater than its lifespan
        if(alive == 1 && months > (204 - age)) {
            alive = 0;
            cout << "The platypus could not live any longer." << endl;
        }
    }
    else
        cerr << "The age cannot be modified." << endl;
}

// fight
void Platypus::fight(Platypus & rival) {
    if(rival.getAliveness() == 0 || alive == 0) {
        cout << "The fight with a dead body does not make sense." << endl;
    }
    else {
        if(((weight / rival.getWeight()) * 50) > ((rand() % 100) + 1)) {
            alive = 1;
            rival.setAliveness(0);
            cout << "Platypus "<< name << " won!" << endl;
        }
        else {
            alive = 0;
            rival.setAliveness(1);
            cout << "Platypus "<< rival.getName() << " won!" << endl;
        }
    }
}


void Platypus::eat() {
    // check if it is alive
    if(alive) {
        weight += (float)((rand() % 5) + 1) * 0.01;
        cout << "The platypus is no longer hungry." << endl;
        // check if it not onverweighted
        if(weight > 5.4) {
            alive = 0;
            cout << "The platypus died from obesity." << endl;
        }
    }
    else {
        cout << "Haha, you cannot feed a dead platypus." << endl;
    }
    
}

Platypus Platypus::hatch() {
    if(mutant != 0) {
        // initialize member values for new platypus
        char newGender;
        if(rand() % 2 == 0) {
            newGender = 'm';
        }
        else
            newGender = 'f';
        float newWeight = (float)((rand() % 10)+ 1) * 0.1;
        
        Platypus newborn(newWeight, 0, 'K', newGender);
    }
    cerr << "This platypus cannot reproduce" << endl;
    return  Platypus();
}


