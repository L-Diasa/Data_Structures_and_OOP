#include <iostream>
#include <stdio.h>
#include "employee.hpp"
#include "waiter.hpp"
#include "owner.hpp"
#include "chef.hpp"

using namespace std;

void wrongInput() {
    cout << "Wrong input. Try again:" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
}

int main() {
    // create
    Employee * empList[6] =
    {
        new Owner("Lika", 175878),
        new Chef("Ani", 767323, "Japanese"),
        new Chef("Jannik", 96875, "Italian"),
        new Waiter("Giga", 46875, 2),
        new Waiter("Mari", 86875, 1),
        new Waiter("Kakha", 36875, 3),
    };
    
    // calculate salary for each employee
    double profit = 6000;
    for(int i = 0; i < 3; i++) {
        empList[i]->calculate_salary(profit);
    }

    empList[3]->calculate_salary(1000);
    empList[4]->calculate_salary(1500);
    empList[5]->calculate_salary(1700);
    
    // display statistics
    for(auto item: empList) {
        item->display(cout);
    }
}

