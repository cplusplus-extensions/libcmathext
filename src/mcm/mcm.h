#ifndef MCM_H
#define MCM_H

#include <iostream>
#include <vector>

class MCM {
    private:
        unsigned long long int a, b;
        std::vector<unsigned long long int>* vect;
    
        void createVect(std::vector<unsigned long long int>* vect1);
    
    public:    
        explicit MCM(unsigned long long int a, unsigned long long int b);
        explicit MCM(std::vector<unsigned long long int>* vect);
        MCM(const MCM& mcm); //Costruttore di copia
        unsigned long long int mcm() const;
        void mcmVect();
};

#endif
