#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest/gtest.h>
#include <fstream>
#include "math_lib.h"

class MathLibTestFixture : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Do some job before test run
    }

    void TearDown() override
    {
        // Do some job after test run
    }
};

TEST_F(MathLibTestFixture, AddTwoValues)
{
    EXPECT_EQ(MathLib::add(10.5, 2.5), 13.0);
    EXPECT_TRUE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0));
    EXPECT_FALSE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0001));
}

TEST_F(MathLibTestFixture, SubTwoValues)
{
    EXPECT_NE(MathLib::subtract(10, 7), 4);
    EXPECT_EQ(MathLib::subtract(10, 7), 3);
}

TEST_F(MathLibTestFixture, MultiplyTwoValues)
{
    EXPECT_EQ(MathLib::multiply(10, 7), 70);
    EXPECT_NE(MathLib::multiply(10, 7), 71);
}

TEST_F(MathLibTestFixture, DivideTwoValues)
{
    EXPECT_EQ(MathLib::divide(10, 2), 5);
    EXPECT_NE(MathLib::divide(10, 2), 3);
}

TEST_F(MathLibTestFixture, DivideByZero)
{
    EXPECT_THROW(MathLib::divide(10, 0), std::invalid_argument);
}

TEST_F(MathLibTestFixture, MedianOfValues)
{
    std::vector<double> arr1 = { 5, 1, 3, 2, 4 };
    EXPECT_EQ(MathLib::median(arr1), 3.0);

    std::vector<double> arr2 = { 5, 1, 3, 2, 4, 6 };
    EXPECT_EQ(MathLib::median(arr2), 3.5);

    std::vector<double> arr3 = { 7 };
    EXPECT_EQ(MathLib::median(arr3), 7.0);

    std::vector<double> arr4 = {};
    EXPECT_THROW(MathLib::median(arr4), std::invalid_argument);
}

TEST_F(MathLibTestFixture, SquareRoot)
{
    EXPECT_THROW(MathLib::sqrt(-1), std::invalid_argument);
}

TEST_F(MathLibTestFixture, LeastCommonMultiple)
{
    EXPECT_EQ(MathLib::leastCommonMultiple(4, 6), 12);
    EXPECT_EQ(MathLib::leastCommonMultiple(7, 5), 35);
    EXPECT_EQ(MathLib::leastCommonMultiple(10, 5), 10);
    EXPECT_NE(MathLib::leastCommonMultiple(4, 6), 3);
}

TEST_F(MathLibTestFixture, IsPrimeTest)
{
    EXPECT_TRUE(MathLib::isPrime(2));
    EXPECT_TRUE(MathLib::isPrime(3));
    EXPECT_FALSE(MathLib::isPrime(4));
    EXPECT_TRUE(MathLib::isPrime(5));
}

TEST_F(MathLibTestFixture, GreatestCommonDivider)
{
    EXPECT_EQ(MathLib::GCD(10, 6), 2);
}

// ВАРІАНТ 2: Тест для функції Фібоначчі
TEST(FibonacciTest, HandlesPositiveInput) {
    EXPECT_EQ(MathLib::fibonacci(0), 0);
    EXPECT_EQ(MathLib::fibonacci(1), 1);
    EXPECT_EQ(MathLib::fibonacci(2), 1);
    EXPECT_EQ(MathLib::fibonacci(9), 34);
    EXPECT_EQ(MathLib::fibonacci(10), 55);
}