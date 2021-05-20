#include <iostream>
#include <limits>
#include <new>
using namespace std;

// called when cin failes
void wrongInput() {
    // message
    cout << "Wrong input. Try again:" << endl;
    cin.clear(); // clears the error flag
    // clear the input buffer and skip to the next line
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // pointers to operator(charachter) and operands(doubles)
    char * oper = new(nothrow) char;
    double * operands = new(nothrow) double[2];

    // if variables were properly allocated
    if(oper != 0 && operands != 0) {

        // Display what the program does and
        // give instructions how to use it
        cout << "\t\tThis is a Simple Calculator" << endl;
        cout << "\t\t============================" << endl;
        cout << "\t\t\t\tHow to Use:" << endl;
        cout << "* Choose an operation you want to perform" << endl;
        cout << "\tor enter q to exit the program." << endl;
        cout << "\n* After choosing an operation:" << endl;
        cout << "  Enter two operands to which you want to" << endl;
        cout << "\t\tapply the selected operation." << endl;
        cout << "\t\t============================\n" << endl;

        while(true) {
            // give directions
            cout << "Enter an operator ( +, -, *, / )"
                " or enter q to quit:" << endl;

            // get an input until it is valid
            while (true) {
                // if cin command fails
                if(!(cin >> *oper)) {}
                // if operation does not exist
                else if((* oper != 'q') && (* oper != '+') &&
                        (* oper != '-') && (* oper != '*') &&
                        (* oper != '/')) {}
                else
                    break;
                
                wrongInput();
             }

            // if q was chosen, then quit
            // else get two operands
            if(* oper == 'q')
                break;
            else {
                // get a valid operand 1
                cout << "Enter the first operand: " << endl;
                while (!(cin >> *operands)) {
                    wrongInput();
                     cin >> * operands;
                 }
                // get a valid operand 2
                cout << "Enter the second operand: " << endl;
                while (true) {
                    if(!(cin >> *(operands + 1))) {}
                    else if((* oper == '/') && (* (operands + 1) == 0)) {
                        cout << "Division by zero cannot be executed."<<endl;
                    }
                    else
                        break;

                    wrongInput();
                 }

                // calculate and output the result
                cout << "Calculation: ";
                switch (*oper) {
                    case '+':
                        cout << *operands << " + " << *(operands + 1) << " = "
                        << (*operands + *(operands + 1)) << "\n" << endl;
                        break;

                    case '-':
                        cout << *operands << " - " << *(operands + 1) << " = "
                        << (*operands - *(operands + 1)) << "\n" << endl;
                        break;

                    case '*':
                        cout << *operands << " * " << *(operands + 1) << " = "
                        << (*operands * *(operands + 1)) << "\n" << endl;
                        break;

                    case '/':
                        cout << *operands <<" / " << *(operands + 1) << " = "
                        << (*operands / *(operands + 1)) << "\n" << endl;
                        break;

                    default:
                        break;
                }
            }
        }
    }

    // delete variables that are no longer needed
    delete oper;
    delete [] operands;

    return 0;
}

