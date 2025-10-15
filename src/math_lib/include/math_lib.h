#pragma once

#include <vector>
#include <exception>
#include <stdexcept>

namespace MathLib
{
    // Function for addition
    template <typename T>
    T add(T a, T b)
    {
        return a + b;
    }

    // Function for subtraction
    template <typename T>
    T subtract(T a, T b)
    {
        return a - b;
    }

    // Function for multiplication
    template <typename T>
    T multiply(T a, T b)
    {
        return a * b;
    }

    // Function for division
    template <typename T>
    T divide(T a, T b)
    {
        if (b == 0)
        {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return a / b;
    }

    // Function for median
    double median(const std::vector<double>& arr);

    // Function to check equality with tolerance
    bool isEqual(double a, double b, double tolerance = 1.e-8f);

    // Function for greatest common divisor (GCD)
    int GCD(int a, int b);

    // Function for least common multiple (LCM)
    int leastCommonMultiple(int a, int b);
    
    // Function to check if a number is prime
    bool isPrime(int n);

    // Function for square root
    template <typename T>
    double sqrt(T a)
    {
        if (a == 0)
            return 0;
        if (a < 0)
            throw std::invalid_argument("Cannot get the square root of a negative number");
        double x = a;
        double result;
        int count = 0;
        while (true)
        {
            count++;
            result = 0.5 * (x + (a / x));
            if (isEqual(result, x, 0.00001))
                break;
            x = result;
        }
        return result;
    }

    // ВАРІАНТ 2: Оголошення функції Фібоначчі
    int fibonacci(int n);
}