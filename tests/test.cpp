#include "gtest/gtest.h"
#include "../libcmathext/libcmathext.cpp"
#include "fibonacci.h"
#include "fibonacci.cpp"

TEST(factorialTestSuite, factorialTest) {
    std::printf("%llu\n", factorial(66LL));
}

TEST(fibonacciTestSuite, fibonacciTest) {
    Fibonacci matematico(1);
    int i=1;
    while(i<10){
        std::cout<<matematico.sumEvenFib(i)<<std::endl;
        ++i;
    }
}