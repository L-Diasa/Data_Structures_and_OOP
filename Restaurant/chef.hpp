#ifndef chef_hpp
#define chef_hpp

#include <stdio.h>
#include "employee.hpp"

// Chef class
// implemented on Employee class
class Chef : public Employee {
public:
    // Member Functions
    // constructor
    Chef(string initName, int initId, string initCuisineOfExp) {
        setName(initName);
        setEmployeeId(initId);
        setEmployeeClass();
        setCuisineOfExp(initCuisineOfExp);
    }
    
    // other
    void display(ostream &out) const {
        Employee::display(out);
        out << "Cuisine of expertise: " << cuisineOfExp << endl;
        out << endl;
    }
    
    // setters
    void calculate_salary(double profit) {
        salary = 10000;
        if(profit > 0){
            salary += profit * 0.20;
        }
    }
    
    
private:
    void setEmployeeClass() {
        employeeClass = 'C';
    }
    
    void setCuisineOfExp(string initCuisineOfExp) {
        cuisineOfExp = initCuisineOfExp;
    }
    
    // Data Members
    string cuisineOfExp;
};

#endif /* chef_hpp */
