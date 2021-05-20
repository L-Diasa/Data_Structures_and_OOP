#ifndef waiter_hpp
#define waiter_hpp

#include <stdio.h>
#include "employee.hpp"

// Waiter class
// implemented on Employee class
class Waiter :  public Employee {
public:
    // Member Functions
    // constructor
    Waiter(string initName, int initId, int initYearsOfService) {
        setName(initName);
        setEmployeeId(initId);
        setEmployeeClass();
        setYearsOfService(initYearsOfService);
    }
    
    // other
    void display(ostream &out) const {
        Employee::display(out);
        out << "Years of service:     " << yearsOfService << endl;
        out << endl;
    }
    
    // setters
    void calculate_salary(double tips) {
        salary = 3000;
        if(tips > 0) {
            salary += tips;
        }
    }
    
private:
    void setEmployeeClass() {
        employeeClass = 'W';
    }
    
    void setYearsOfService(int initYearsOfService) {
        yearsOfService = initYearsOfService;
    }
    
    // Data Members
    int yearsOfService;
};


#endif /* waiter_hpp */
