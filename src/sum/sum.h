#ifndef SUM_H
#define SUM_H

#include <iostream>

class Sum {
    private:
        int valueA, valueB, target;
    
    public:
        explicit Sum(int val, int val1 = 0, int val2 = 0);
        int oddIntSum(int value);
        int evenIntSum(int value);
        int sumMultiples(int valueA, int valueB, int target);
        int sumDivisibleBy(int N, int target);
        unsigned long long int digitSum(std::string str);
};

#endif
