#ifndef MCM_H
#define MCM_H

#include <iostream>
#include <vector>

class MCM {
    private:
        int a, b;
        std::vector<int>* vect;
    
        void createVect(std::vector<int>* vect);
    
    public:    
        explicit MCM(int a, int b);
        explicit MCM(std::vector<int>* vect);
        MCM(const MCM& mcm); //Costruttore di copia
        int mcm();
        int mcmVect();
};

#endif
