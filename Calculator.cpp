#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <limits>
#include <ios>

using namespace std;

// Function to pre validate inputs
double getValidNumber(bool integerOnly = false, bool allowNegative = true, bool disallowZero = false) 
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    string input;
    double number;
    
    while (true) 
    {
        SetConsoleTextAttribute(hConsole, 15);
        cout << "Enter a " << (integerOnly ? "whole number (integer)" : "number");

        if(!allowNegative) 
            cout << " (non-negative)";

        cout << ": ";
        
        getline(cin, input);
        stringstream ss(input);

        // Check for non numbers
        if(!(ss >> number) || !(ss.eof())) 
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        // Check for negative numbers
        if(!allowNegative && number < 0) 
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: Negative numbers are not allowed.\n";
            continue;
        }

        // Check for zeros
        if(disallowZero && number == 0) 
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: Zero is not allowed for this operation.\n";
            continue;
        }

        // Check for integers
        if(integerOnly && number != static_cast<int>(number)) 
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: You entered a decimal. Please enter a whole number.\n";
            continue;
        }

        return number; // Valid number
    }
}

bool addition(double a, double b)
{
    cout << endl << a << " + " << b << " = " << (a + b) << endl << endl;
    return 1;
}

bool subtraction(double a, double b)
{
    cout << endl << a << " - " << b << " = " << (a - b) << endl << endl;
    return 1;
}

bool multiplication(double a, double b)
{
    cout << endl << a << " * " << b << " = " << (a * b) << endl << endl;
    return 1;
}

bool division(double a, double b)
{
    return 1;
}

bool modulo(int a, int b)
{
    return 1;
}

int main() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    string operation;
    double operationChoice;
    int select;
    
    double a,b;
    int d,e;

    while(true)
    {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Operation List:\n1 - Addition \t2 - Subtraction \t3 - Multiplication \t4 - Division\n5 - Modulo \t6 -  \t7 -  \t8 - \n\n";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "Enter operation: \t" ;

        getline(cin, operation);
        stringstream ss(operation);

        // Check for non numbers
        if(!(ss >> operationChoice) || !(ss.eof())) 
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Invalid input. Please enter an integer between 1- 8.\n\n";
            continue;
        }

        // Check for numbers not in the range
        if(operationChoice != static_cast<int>(operationChoice) || operationChoice <= 0 || operationChoice > 8)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Invalid input. Please enter an integer between 1- 8.\n\n";
            continue;
        }

        select = static_cast<int>(operationChoice);
        
        cout << endl;
        switch(select)
        {
            case 1:
            SetConsoleTextAttribute(hConsole, 14);
            cout << "Addition operation selected: a + b" << endl;
            a = getValidNumber();
            b = getValidNumber();
            SetConsoleTextAttribute(hConsole, 10);
            addition(a,b);
            break;
            case 2:
            cout << "Subtraction operation selected: a - b" << endl;
            break;
            case 3:
            cout << "Mulitpication operation selected: a * b" << endl;
            break;
            case 4:
            cout << "Division operation selected: a / b" << endl;
            break;
            case 5:
            cout << "Modulo operation selected: a % b" << endl;
            break;
        }

        SetConsoleTextAttribute(hConsole, 14);
        cout << "Continue Calculating? (Y/N): " << endl;
        while(true)
        {
            SetConsoleTextAttribute(hConsole, 15);
            cin >> operation;
            if(operation == "Y" || operation == "y")
            {
                cin.clear();  
                cin.ignore(1000, '\n'); 
                system("cls");
                break;
            }
            else if(operation == "N" || operation == "n")
            {
                return 0;
            }
            else
            {
                cin.clear();  
                cin.ignore(1000, '\n'); 
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Please enter Y/N:" << endl;
            }
        } 
    }
    return 0;
}
