#include "math_lib.h"
#include <cmath>
#include <algorithm>
#include <numeric> // Для std::abs, std::llabs

namespace MathLib
{
    // Function to check equality with tolerance
    bool isEqual(double a, double b, double tolerance)
    {
        return std::fabs(a - b) <= tolerance;
    }

    // Function to calculate the median of a vector
    double median(const std::vector<double>& arr)
    {
        if (arr.empty())
        {
            throw std::invalid_argument("Array is empty, median cannot be calculated.");
        }

        std::vector<double> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());

        size_t size = sortedArr.size();
        if (size % 2 == 0)
        {
            return (sortedArr[size / 2 - 1] + sortedArr[size / 2]) / 2.0;
        }
        else
        {
            return sortedArr[size / 2];
        }
    }

    // Function for greatest common divisor (GCD) - ВИКОРИСТОВУЄМО ВАШУ
    int GCD(int a, int b)
    {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Function to check if a number is prime - ВИКОРИСТОВУЄМО ВАШУ ОПТИМІЗОВАНУ ВЕРСІЮ
    bool isPrime(int n)
    {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }

    // Function to calculate least common multiple (LCM) - ВИКОРИСТОВУЄМО ВАШУ
    int leastCommonMultiple(int a, int b)
    {
        if (a == 0 || b == 0) return 0;
        int gcd = GCD(a, b);
        // prevent overflow by using long long for product
        long long prod = 1LL * a / gcd * b;
        return static_cast<int>(std::llabs(prod));
    }

    // ВАРІАНТ 2: Реалізація функції Фібоначчі
    int fibonacci(int n)
    {
        if (n < 0) throw std::invalid_argument("Negative fibonacci index");
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

}