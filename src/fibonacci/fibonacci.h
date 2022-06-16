#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>

class Fibonacci {
    private:
    int index;
    
    public:
    explicit Fibonacci(int index) {
        this->index = index;
    }
    int sumEvenFib(int target);
    int binet(int index);
};

#endif
