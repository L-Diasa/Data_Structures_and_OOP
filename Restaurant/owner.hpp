#ifndef owner_hpp
#define owner_hpp

#include <stdio.h>
#include "employee.hpp"


// Owner class
// implemented on Employee class
class Owner : public Employee {
public:
    // Member Functions
    // constructor
    Owner(string initName, int initId) {
        setName(initName);
        setEmployeeId(initId);
        setEmployeeClass();
    }
    
    // other member funtions
    void calculate_salary(double profit) {
        salary = 15000;
        if(profit > 0) {
            salary += profit * 0.60;
        }
    }
    
    void display(ostream &out) const {
        Employee::display(out);
        out << endl;
    }
    
private:
    void setEmployeeClass() {
        employeeClass = 'O';
    }
};


#endif /* owner_hpp */
