#include "math_lib.h"
#include <cmath>
#include <algorithm>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return std::fabs(a - b) <= tolerance;
    }

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

    int leastCommonMultiple(int a, int b)
    {
        if (a == 0 || b == 0) return 0;
        int gcd = GCD(a, b);
        // prevent overflow by using long long for product
        long long prod = 1LL * a / gcd * b;
        return static_cast<int>(std::llabs(prod));
    }

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
