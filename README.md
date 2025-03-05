# BasicCalculator

# This project is made with C++ language
# The project is of a basic calculator, with the following operations:
# 1. Addition           required
# 2. Subtraction        required
# 3. Multiplication     required
# 4. Division           required
# 5. Modulus            bonus
# 6. Power              bonus
# 7. Sqaure Root        bonus
# 8. Factorial          bonus

# **To compile and run the Calculator.cpp**
# Open the Developer Command Prompt for VS 2022
# Go to where the Calculator.cpp is located using 'cd'
# Type "cl Calculator.cpp" to compile the file into a '.exe'
# Run the "Calculator.exe"


# In the Calculator.cpp, there 9 functions:

# 1
# long double getValidNumber(bool integerOnly = false, bool allowNegative = true, bool disallowZero = false)
# This function is important as it validates the user input to fit the other operation functions so that it would prevent potential unexpected errors that may occur. With its three parameters, it can be set to only allow specific numerical inputs, for example:
# Decimal numbers
# Integers
# Positive numbers/integers
# Non-zero numbers

# 2
# void addition(long double a, long double b)
# This Functions adds the 2 numbers provided.

# 3
# void subtraction(long double a, long double b)
# This Functions minus the 2 numbers provided.

# 4
# void multiplication(long double a, long double b)
# This Functions multiples the 2 numbers provided.

# 5
# void division(long double a, long double b)
# This Functions divides the 2 numbers provided.
# Edge case zero: the getValidNumber function prevents the input of zero before the number is pass into this function.

# 6
# void modulo(long int a, long int b)
# This Functions modulo the 2 numbers provided.
# Edge case zero: the getValidNumber function prevents the input of zero before the number is pass into this function.
# Edge case decimal: the getValidNumber function prevents the input of decimal numbers before the number is pass into this function.
# Edge case negative: the getValidNumber function prevents the input of negative numbers before the number is pass into this function.

# 7
# void power(long double a, long int b)
# This Functions powers the 2 numbers provided.
# Edge case zero: zero power would default output a 1.
# Edge case decimal: the getValidNumber function prevents the input of decimal numbers before the number is pass into this function.
# Edge case negative: the getValidNumber function prevents the input of negative numbers before the number is pass into this function.

# 8
# void squareroot(long int a)
# This Functions findd the square root of the number provided using Heron's method for computing square root of non-negative integers using an iterative approximation technique.
# Edge case zero: square root of zero would default output a 0.
# Edge case decimal: the getValidNumber function prevents the input of decimal numbers before the number is pass into this function.
# Edge case negative: the getValidNumber function prevents the input of negative numbers before the number is pass into this function.

# 9
# void factorial(long int a)
# This Functions find the fatorial of the number provided.
# Edge case zero: factorial of zero would default output a 1.
# Edge case decimal: the getValidNumber function prevents the input of decimal numbers before the number is pass into this function.
# Edge case negative: the getValidNumber function prevents the input of negative numbers before the number is pass into this function.