#ifndef employee_hpp
#define employee_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

// Abstract class
class Employee {
public:
    // Member Functions
    // getters
    char getEmployeeClass() {
        return employeeClass;
    }
    
    // other
    virtual void display(ostream &out) const {
        out << "Name:                 " << name << endl;
        out << "Employee ID:          " << employeeId << endl;
        out << "Salary:               $" << salary << endl;
        out << "Employee class:       " << employeeClass << endl;
    }
    
    // setters
    virtual void calculate_salary(double profit) = 0;
    

protected:
    void setName(string initName) {
        name = initName;
    }
    
    void setEmployeeId(int initEmployeeId) {
        employeeId = initEmployeeId;
    }
    
    virtual void setEmployeeClass() = 0;
    
    // Data Members
    string name;
    int employeeId;
    double salary;
    char employeeClass;
};

#endif /* employee_hpp */
