#ifndef MCD_H
#define MCD_H

#include <iostream>
#include <vector>
#include <tuple>

class MCD {
    private:
        unsigned long long int a, b;
        std::vector<int>* vect;
    
    public:
        explicit MCD(unsigned long long int a, unsigned long long int b);
        explicit MCD(std::vector<int>* vect = nullptr);
    
        //Costruttore di copia
        MCD(const MCD& mcd);    
        ~MCD();    
        unsigned long long int gcd() noexcept;
        unsigned long long int mcd2() noexcept;
        unsigned long long int mcd() noexcept;
        std::tuple<int, int, int> extendedGCD(int s, int m);
};

#endif
