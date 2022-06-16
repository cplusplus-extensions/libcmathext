#ifndef MCD_H
#define MCD_H

#include <iostream>
#include <vector>

class MCD {
    private:
        long long int a, b;
        std::vector<int>* vect;
    
    public:
        explicit MCD(long long int a, long long int b);
        explicit MCD(std::vector<int>* vect = nullptr);
    
        //Costruttore di copia
        MCD(const MCD& mcd);    
        ~MCD();    
        unsigned long long int gcd();
        unsigned long long int mcd2();
        unsigned long long int mcd();
};

#endif
