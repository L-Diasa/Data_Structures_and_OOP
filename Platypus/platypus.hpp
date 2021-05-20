/*-- platypus.h ---------------------------------
 This header file defines the data type Platypus
 for creating objects - platypuses.
------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef platypus_hpp
#define platypus_hpp

class Platypus {
public:
    //constructors:
    Platypus();
    
    Platypus(float initWeight, short initAge, char initName, char initGender);
    
    //getters
    float getWeight() const;
    short getAge() const;
    char getName() const;
    char getGender() const;
    bool getAliveness() const;
    bool getMutantness() const;
    
    //setters
    void setWeight(float initWeight);
    void setAge(short initAge);
    void setName(char initName);
    void setGender(char initGender);
    void setAliveness(bool initAlive);
    void setMutantness(bool initMutant);
    
    //other operations
    void print(ostream & out) const;
    void age_me(short months = 1);
    void fight(Platypus & rival);
    void eat();
    Platypus hatch();
    
private:
    //date members
    float weight;
    short age;
    char name;
    char gender;
    bool alive;
    bool mutant;
};

#endif /* platypus_hpp */
