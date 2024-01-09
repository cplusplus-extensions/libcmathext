#include "mcm.h"
#include "../mcd/mcd.h"

void MCM::createVect(std::vector<unsigned long long int>* vect1) {
    for(int i = 0; i < vect1->size(); i++) {
        this->vect->at(i) = vect1->at(i);
    }
}

MCM::MCM(unsigned long long int a, unsigned long long int b) {
    this->a = a;
    this->b = b;
    vect = nullptr;
}

MCM::MCM(std::vector<unsigned long long int>* vect) {
    a = -1;
    b = -1;
    if(vect != nullptr) {
        this->vect = new std::vector<unsigned long long int>(vect->size());
        createVect(vect);
    } else {
        this->vect = nullptr;
    }
}

MCM::MCM(const MCM& mcm) {
    a = mcm.a;
    b = mcm.b;
    vect = new std::vector<unsigned long long int>(mcm.vect->size());
    createVect(mcm.vect);
}

unsigned long long int MCM::mcm() const {
    MCD* tempRes = new MCD(a, b);
    return (a*b)/tempRes->gcd();
}

void MCM::mcmVect() {
    if(vect != nullptr) {
        unsigned long long tempRes;
        auto it = vect->begin();
        while(vect->size() > 1) {
            a = *it;
            b = *(it + 1);
            tempRes = mcm();
            vect->erase(it, it + 2);
            vect->insert(vect->begin(), tempRes);
        }
    }
}