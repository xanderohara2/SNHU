/*
 * Calculator.cpp
 *
 *  Date: 5-13-2024
 *  Author: Xander O'Hara
 */

#include <iostream>

using namespace std;

int main() {
    char statement[100];
    int op1, op2;
    char operation;
    char answer = 'Y'; //Fixed quotes to ' '

    while (answer == 'Y' || answer == 'y') { //Added lower or Caps for input
        cout << "Enter expression" << endl;
        cin >> op2 >> operation >> op1;

        if (operation == '+') // removed the semicolon
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
        else if (operation == '-') // corrected syntax for this and for * and /
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        else if (operation == '*')
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        else if (operation == '/')
            cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
        else
            cout << "Sorry, Cannot Calculate." << endl; // Added so if bad input doesnt kill program

        cout << "Do you wish to evaluate another expression? (Y/N)" << endl;
        cin >> answer;

        if (answer == 'N' || answer == 'n') {
            cout << "Program Finished." << endl;  // Added output for when input is N or n
            break;
        }
    }

    return 0;
}
