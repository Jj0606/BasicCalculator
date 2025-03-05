#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <limits>
#include <ios>
#include <iomanip>

using namespace std;

// Function to pre validate inputs
long double getValidNumber(bool integerOnly = false, bool allowNegative = true, bool disallowZero = false) 
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    string input;
    long double number;
    
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
        if(integerOnly && number != static_cast<long int>(number)) 
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: You entered a decimal. Please enter a whole number.\n";
            continue;
        }

        return number; // Valid number
    }
}

// Function for addition
bool addition(long double a, long double b)
{
    cout << endl << defaultfloat << setprecision(10) << a << " + " << b << " = " << (a + b) << endl << endl;
    return 1;
}

// Function for subtraction
bool subtraction(long double a, long double b)
{
    cout << endl << defaultfloat << setprecision(10) << a << " - " << b << " = " << (a - b) << endl << endl;
    return 1;
}

// Function for multiplication
bool multiplication(long double a, long double b)
{
    cout << endl << defaultfloat << setprecision(10) << a << " * " << b << " = " << (a * b) << endl << endl;
    return 1;
}

// Function for division
bool division(long double a, long double b)
{
    cout << endl << defaultfloat << setprecision(10) << a << " / " << b << " = " << (a / b) << endl << endl;
    return 1;
}

// Function for modulus
bool modulo(long int a, long int b)
{
    cout << endl << defaultfloat << a << " % " << b << " = " << (a % b) << endl << endl;
    return 1;
}

// Function for positive integer power
bool power(long double a, long int b)
{
    long double result; 

    if(b != 0)
    {
        result = a;
        for(int i = 1; i < b; i++)
        {
            result *= a;
        }
        cout << endl << defaultfloat << a << "^" << b << " = " << result << endl << endl;
    }
    else
    {
        cout << endl  << a << "^" << b << " = 1"  << endl << endl;
    }
    return 1;
}

// Function for square root
bool squareroot(long double a)
{
    long double error = 0.00001; // Precision of result
    long double result = a;

    while ((result - a / result) > error) // Loop till precision is reached 
    {
        result = (result + a / result) / 2;
    }

    cout << endl << defaultfloat << setprecision(5) << "sqrt " << a  << " = " << result << endl << endl;
    return 1;
}

// Function for factorial
bool factorial(long int a)
{
    if(a != 0)
    {
        long int result = 1;
        for(int i = a; i > 0; i--)
        {
            result *= i;
        }
        cout << endl << defaultfloat << a << "! = " << result << endl << endl;
    }
    else
    {
        cout << endl  << "0! = 1"  << endl << endl;
    }
    return 1;
}

int main() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    string operation;
    double operationChoice;
    int select;
    
    long double a,b;
    long int d,e;

    while(true)
    {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Operation List:\n1 - Addition \t2 - Subtraction \t3 - Multiplication \t4 - Division\n5 - Modulo \t6 - Power \t\t7 - Square Root \t8 - Factorial\n\n";
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

        // Check for numbers not in the range (0 - 8)
        if(operationChoice != static_cast<int>(operationChoice) || operationChoice <= 0 || operationChoice > 8)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Invalid input. Please enter an integer between 1- 8.\n\n";
            continue;
        }

        select = static_cast<long int>(operationChoice);
        
        cout << endl;
        SetConsoleTextAttribute(hConsole, 14);
        switch(select)
        {
            case 1:
            cout << "Addition operation selected: a + b\n";
            a = getValidNumber();
            b = getValidNumber();
            SetConsoleTextAttribute(hConsole, 10);
            addition(a,b);
            break;
            case 2:
            cout << "Subtraction operation selected: a - b\n";
            a = getValidNumber();
            b = getValidNumber();
            SetConsoleTextAttribute(hConsole, 10);
            subtraction(a,b);
            break;
            case 3:
            cout << "Mulitpication operation selected: a * b\n";
            a = getValidNumber();
            b = getValidNumber();
            SetConsoleTextAttribute(hConsole, 10);
            multiplication(a,b);
            break;
            case 4:
            cout << "Division operation selected: a / b\n";
            a = getValidNumber();
            b = getValidNumber(false, true, true);
            SetConsoleTextAttribute(hConsole, 10);
            division(a,b);
            break;
            case 5:
            cout << "Modulo operation selected: a % b\n";
            a = getValidNumber(true);
            b = getValidNumber(true, false, true);
            SetConsoleTextAttribute(hConsole, 10);
            modulo(a,b);
            break;
            case 6:
            cout << "Power operation selected: a^b\n";
            a = getValidNumber();
            b = getValidNumber(true, false);
            SetConsoleTextAttribute(hConsole, 10);
            power(a,b);
            break;
            case 7:
            cout << "Square root operation selected: sqrt a\n";
            a = getValidNumber(true, false);
            SetConsoleTextAttribute(hConsole, 10);
            squareroot(a);
            break;
            case 8:
            cout << "Factorial operation selected: a!\n";
            a = getValidNumber(true, false);
            SetConsoleTextAttribute(hConsole, 10);
            factorial(a);
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
