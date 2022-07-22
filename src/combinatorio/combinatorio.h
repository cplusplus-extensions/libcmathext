#ifndef COMBINATORIO_H
#define COMBINATORIO_H

#include <iostream>
#include <vector>
#include "../libcmathext/libcmathext.h"
#include "../libcmathext/libcmathext.cpp"


unsigned long long int permWithRepetition(unsigned long long int n, const std::vector<unsigned long long int>& v);
unsigned long long int binomial(unsigned long long int n, unsigned long long int k);
unsigned long long int newton(unsigned long long int a, unsigned long long int b, unsigned long long int exp);

#endif //COMBINATORIO_H
