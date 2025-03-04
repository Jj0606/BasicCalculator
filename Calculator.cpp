#include <iostream>
#include <string>

float addition(float a, float b)
{
    return a + b;
}

float subtraction(float a, float b)
{
    return a - b;
}

float multiplication(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    return a / b;
}

int main() {
    int select;
    float a,b,result;

    std::cout << "Operation List:" << std::endl;
    std::cout << "1 - Addition \t2 - Subtraction \t3 - Multiplication" << std::endl;
    std::cout << "4 - Division \t4 - Square Root \t5 - " << std::endl;
    std::cout << "6 -  \t7 -  \t8 - " << std::endl;
    std::cout << "Enter operation: \t";
    std::cin >> select;
    std::cout << "Enter first number: \t";
    std::cin >> a;
    std::cout << "Enter second number: \t";
    std::cin >> b;
    switch(select)
    {
        case 1:
        result = addition(a,b);
        break;
    }
    std::cout << result << std::endl;
    std::cin >> select;
    return 0;
}
