#include <iostream>
#include <string>
#include <limits>
#include <ios>

bool addition(double a, double b)
{
    std::cout << std::endl << a << " + " << b << " = " << (a + b) << std::endl << std::endl;
    return 1;
}

bool subtraction(double a, double b)
{
    std::cout << std::endl << a << " - " << b << " = " << (a - b) << std::endl << std::endl;
    return 1;
}

bool multiplication(double a, double b)
{
    std::cout << std::endl << a << " * " << b << " = " << (a * b) << std::endl << std::endl;
    return 1;
}

bool division(double a, double b)
{
    if (b == 0) {
        std::cout << "Invalid input. Enter a non-zero rational number for b: ";

        // Loop until valid input is received and b is non-zero
        while (true) {
            std::cin >> b;

            if (std::cin.fail() || b == 0) {
                std::cin.clear();  // Clear the fail state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid input. Enter a non-zero rational number for b: ";
            } else {
                break; // Valid non-zero input, exit loop
            }
        }
    }
    std::cout << std::endl << a << " / " << b << " = " << (a / b) << std::endl << std::endl;
    return 1;
}

int main() {
    int select;
    double a,b;
    std::string c;

    while(true)
    {
        std::cout << "Operation List:" << std::endl;
        std::cout << "1 - Addition \t2 - Subtraction \t3 - Multiplication \t4 - Division" << std::endl;
        std::cout << "5 -  \t6 -  \t7 -  \t8 - " << std::endl << std::endl;
        std::cout << "Enter operation: \t" ;

        while (!(std::cin >> select) || select < 1 || select > 9) // Check if input fails
        {
            std::cin.clear();  // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
            std::cout << "Please enter a valid integer between 1 - 9: ";
        }
        
        std::cout << std::endl;
        switch(select)
        {
            case 1:
            std::cout << "Addition operation selected: a + b" << std::endl;
            break;
            case 2:
            std::cout << "Subtraction operation selected: a - b" << std::endl;
            break;
            case 3:
            std::cout << "Mulitpication operation selected: a * b" << std::endl;
            break;
            case 4:
            std::cout << "Division operation selected: a / b" << std::endl;
            break;
        }

        std::cout << "Enter a: \t";
        while (!(std::cin >> a)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a rational number for a: ";
        }

        std::cout << "Enter b: \t";
        while (!(std::cin >> b)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a rational number for b: ";
        }

        switch(select)
        {
            case 1:
            addition(a,b);
            break;
            case 2:
            subtraction(a,b);
            break;
            case 3:
            multiplication(a,b);
            break;
            case 4:
            division(a,b);
            break;
        }

        std::cout << "Continue Calculating? (Y/N): " << std::endl;
        while(true)
        {
            std::cin >> c;
            if(c == "Y" || c == "y")
            {
                system("cls");
                break;
            }
            else if(c == "N" || c == "n")
            {
                return 0;
            }
            else
            {
                std::cin.clear();  
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cout << "Please enter Y/N:" << std::endl;
            }
        } 
    }
    return 0;
}
