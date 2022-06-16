#ifndef GAUSS_H
#define GAUSS_H

#include <iostream>

class Gauss {
    private:
    long long int value;
    
    public:
    explicit Gauss(long long int val) {
        value = val;
    }
    
    long long int gaussSum(long long int value);
};

#endif
